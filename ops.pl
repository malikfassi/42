# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ops.pl                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loimans <loimans@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 06:29:18 by loimans           #+#    #+#              #
#    Updated: 2013/12/24 13:53:47 by loimans          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

use strict;
use warnings;
use Getopt::Long;
use Time::HiRes qw( time );

srand(time);

my $push_swap	= "push_swap";
my $help		= "";
my $verbose		= "";
my $runonly		= "";
my $file		= "";

GetOptions
(
	"help"		=> \$help,
	"input=s"	=> \$push_swap,
	"verbose"	=> \$verbose,
	"runonly"	=> \$runonly,
	"file=s"	=> \$file,
) or die;

sub display_help
{
	print <<__EOF__;
Usage: perl ops.pl [-i path] [-f file]

	h : print this help message
	v : print error information on stderr
	r : run only mode

	i path : path to push_swap executable
	f file : input file to check
__EOF__
}

sub sorted
{
	my $a = $_[0];

	foreach (@_)
	{
		return 0 if $a > $_;
		$a = $_;
	}
	return 1;
}

{
	sub swap {
		@_[0, 1] = @_[1, 0] if $#_ > 0;
	}

	sub rotate {
		push(@{$_[0]}, shift(@{$_[0]}));
	}

	sub rrotate {
		unshift(@{$_[0]}, pop(@{$_[0]}));
	}

	my %op = (
		sa	=>	sub { swap(@{$_[0]}) },
		sb	=>	sub { swap(@{$_[1]}) },
		ss	=>	sub { swap(@{$_[0]}); swap(@{$_[1]}) },
		pa	=>	sub { unshift(@{$_[0]}, shift(@{$_[1]})) if (@{$_[1]}) },
		pb	=>	sub { unshift(@{$_[1]}, shift(@{$_[0]})) if (@{$_[0]}) },
		ra	=>	sub { rotate($_[0]) },
		rb	=>	sub { rotate($_[1]) },
		rr	=>	sub { ($a, $b) = @_; rotate($a) ; rotate($b) },
		rra	=>	sub { rrotate($_[0]) },
		rrb	=>	sub { rrotate($_[1]) },
		rrr	=>	sub { ($a, $b) = @_; rrotate($a); rrotate($b) }
	);

	sub process_operators
	{
		my ($list_a, $list_b, $list_ops) = @_;

		foreach (split(/ /, $list_ops))
		{
			$op{$_}->($list_a, $list_b) if exists $op{$_};
		}
	}
}

sub perror_list
{
	print STDERR "$_[0] = (";
	print STDERR "@{$_[1]}" if @{$_[1]};
	print STDERR ")\n";
}

sub run_pushswap
{
	my $runtime;

	$runtime = time();
	chomp($_[1] = `./$push_swap $_[0]`);
	$runtime = time() - $runtime;
}

{
	my @nums = 0 .. 65535;
	sub new_list
	{
		map { splice(@nums, int(rand @nums), 1) } 1 .. $_[0];
	}
}

sub process_file
{
	my @list_a;
	my @list_b;
	my $arg;
	my $ops;

	open(FILE, $file) or die("Could not open file.");
	while( my $line = <FILE>)
	{
		if ($. % 2 == 0)	
		{	
			chomp($ops = $line);
			process_operators(\@list_a, \@list_b, $ops);
			if (sorted(@list_a) == 0 || @list_b)
			{
				print "[\e[0;31mFAIL\e[0m] bad pushswap\n";
				if ($verbose)
				{
					print STDERR "$arg\n$ops\n";
					perror_list("List A", \@list_a);
					perror_list("List B", \@list_b);
				}
			}
			else
			{
				printf("[\e[0;33mDONE\e[0m] %d operations\n", $ops =~ tr/ // + 1);
				perror_list("List A", \@list_a);
				perror_list("List B", \@list_b);
			}
		}
		else
		{
			chomp($arg = $line);
			@list_a = split(/ /, $arg);
			@list_b = ();
		}
	}
	close(FILE);
}

sub process_list
{
	my @list_a = new_list($_[0]);
	my @list_b = ();

	my $ops;
	my $arg = join(" ", @list_a);
	my $exec_time = run_pushswap($arg, $ops);

	print "$arg\n$ops\n" and return if $runonly;
	process_operators(\@list_a, \@list_b, $ops);
	if (sorted(@list_a) == 0 || @list_b)
	{
		print "[\e[0;31mFAIL\e[0m] bad pushswap on $_[0] items\n";
		if ($verbose)
		{
			print STDERR "$arg\n$ops\n";
			perror_list("List A", \@list_a);
			perror_list("List B", \@list_b);
		}
	}
	else
	{
		printf("[\e[0;33mDONE\e[0m] %d operations ", $ops =~ tr/ // + 1);
		printf("on $_[0] items in %.3fs\n", $exec_time);
	}
}

sub main
{
	display_help() and exit if $help;
	process_file() and exit if $file;
	for (my $n = 2; $n < 16384; $n += $n)
	{
		process_list($n);
		process_list($n);
		process_list($n);
	}
}

main();