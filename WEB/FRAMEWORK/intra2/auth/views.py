from django.contrib.auth import authenticate, login, logout
from auth.forms import ConnexionForm, RegistrationForm
from django.shortcuts import render, redirect, render_to_response
from django.core.urlresolvers import reverse
from django.contrib.auth.decorators import login_required
from django.core.context_processors import csrf
from django.http import HttpResponseRedirect
from django.template import RequestContext
from django.views.decorators.csrf import ensure_csrf_cookie, csrf_protect

from django.core.mail import send_mail
from auth.models import UserProfile
from datetime import datetime
from time import sleep

@ensure_csrf_cookie
@csrf_protect
def login_user(request):
    if request.user.is_authenticated():
        return HttpResponseRedirect('/')
    error = False
    if request.method == "POST":
        if "SendEmail" in request.POST:
            allusers = UserProfile.objects.all()
            for eachuser in allusers:
                if (eachuser.subscribed):
                    send_mail('My django-app', 'Hello, ' + eachuser.username +".\n It is : "+ datetime.now().strftime("%I:%M%p on %B %d, %Y"), 'malikfassifihri@gmail.com',[eachuser.email], fail_silently=False)
        else:   
            form = ConnexionForm(request.POST)
            if form.is_valid():
                username = form.cleaned_data["username"]
                password = form.cleaned_data["password"]
                user = authenticate(username=username, password=password)
                if user:
                    login(request, user)
                    return HttpResponseRedirect('/', {"user" :user})
                else:
                    error = True
    else:
        form = ConnexionForm()
    return render_to_response('form.html', RequestContext(request,{'form' : form, 'title' : "Login"}))

@csrf_protect
@ensure_csrf_cookie
@login_required                                                                                           
def logout_user(request):
    logout(request)                                                                         
    return redirect(reverse(home))

@ensure_csrf_cookie
@csrf_protect
def home(request):
    return render_to_response("home.html", RequestContext(request, {}))

@ensure_csrf_cookie
@csrf_protect
def signin(request):
    if request.user.is_authenticated():
        return HttpResponseRedirect('/', {"user" :request.user})
    args = {}
    args.update(csrf(request))
    args['title']="Sign In"
    if (request.method == 'POST'):
        form = RegistrationForm(request.POST)
        args['form'] = form
        if form.is_valid():
            form.save()
            return (HttpResponseRedirect("/"))
    else:
        args['form'] = RegistrationForm()
    return (render_to_response('form.html', args, context_instance=RequestContext(request)))






