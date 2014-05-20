from django.conf.urls import patterns, include, url
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
	url(r'^polls/', include('polls.urls', namespace="polls")),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^login/', 'auth.views.login_user', name="login_user"),
    url(r'^logout/', 'auth.views.logout_user', name="logout_user"),
    url(r'^$', 'auth.views.home', name="home"),
    url(r'^signin/$', 'auth.views.signin', )

)