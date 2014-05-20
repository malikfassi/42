# Create your views here.
from django.shortcuts import render, redirect, render_to_response
from django.core.urlresolvers import reverse
from django.contrib.auth.decorators import login_required
from django.core.context_processors import csrf
from django.http import HttpResponseRedirect
from django.template import RequestContext
from django.views.decorators.csrf import ensure_csrf_cookie, csrf_protect
from django.contrib.auth.models import User
from django.shortcuts import get_list_or_404, get_object_or_404


from auth.models import UserProfile
from forum.models import Category, Thread
from forum.forms import CategoryForm, ThreadForm
from django.utils.translation import ugettext


@login_required
def get_all_parent_category():
    allcat = Category.objects.all()
    return (allcat)

@login_required
def get_cat(request, cat):
    if (get_list_or_404(Category, title=cat)):
        threads = Thread.objects.filter(category=cat)
    allcat = Category.objects.all()
    parent = Category.objects.get(title=cat).parent
    return (render_to_response("threads.html", RequestContext(request, {'threads' : threads, 'cat' : cat, 'allcat' : allcat, 'parent' : parent})))

@login_required
def get_thread(request,cat, thread):
    message = get_object_or_404(Thread, id=thread)
    allcat = Category.objects.all()
    parent = Category.objects.get(title=cat).parent
    return (render_to_response("threads.html", RequestContext(request, {'message' : message, 'cat':cat, 'allcat':allcat, 'parent' : parent})))

@login_required
def forum(request):
    allcat = Category.objects.all()
    return (render_to_response("forum.html", RequestContext(request, {'allcat' : allcat})))

@login_required
@csrf_protect
def new_thread(request, cat):
    if (request.method == "POST"):
        form = ThreadForm(request.POST)
        if form.is_valid():
            obj = form.save(commit=False)
            obj.author = request.user
            obj.category = cat
            obj.save()
            return HttpResponseRedirect('/forum/cat-'+cat)
        else:
            error = True
    else:
        form = ThreadForm()
    return (render_to_response("form.html", RequestContext(request, {'form':form, 'title':"Create new thread"})))

@login_required
@csrf_protect
def new_cat(request):
    if (request.method == "POST"):
        form = CategoryForm(request.POST)
        if form.is_valid():
            form.save()
            return HttpResponseRedirect('/forum')
        else:
            error = True
    else:
        form = CategoryForm()
    return (render_to_response("form.html", RequestContext(request, {'form':form, 'title':"Create new category"})))

login_required
@csrf_protect
def new_sub_cat(request, cat):
    if (request.method == "POST"):
        form = CategoryForm(request.POST)
        if form.is_valid():
            obj = form.save(commit=False)
            obj.parent = Category.objects.get(title=cat)
            obj.save()
            return HttpResponseRedirect('/forum/cat-'+cat)
        else:
            error = True
    else:
        form = CategoryForm()
    return (render_to_response("form.html", RequestContext(request, {'form':form, 'title':"Create new category"})))

