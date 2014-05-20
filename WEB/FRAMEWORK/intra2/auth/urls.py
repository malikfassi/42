from django.conf.urls import patterns, url
urlpatterns = patterns('',
	(r'^$', 'django.contrib.auth.views.login_user', {'template_name': 'login.html'}),
	(r'^login', 'django.contrib.auth.views.login_user', {'template_name': 'login.html'}),
    (r'^logout', 'django.contrib.auth.views.logout_user', name="logout_user")
)