from django.conf.urls import patterns, include, url

urlpatterns = patterns('',
    # Examples
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    url(r'^$', 'forum.views.forum', name="forum"),
    url(r'^cat-(?P<cat>.[^/]*)$', 'forum.views.get_cat'),
    url(r'^cat-(?P<cat>.*)/(?P<thread>.*)$', 'forum.views.get_thread'),
    url(r'^new_cat/$', 'forum.views.new_cat', name="new_cat"),
    url(r'^new_thread/(?P<cat>.*)$', 'forum.views.new_thread'),
    url(r'^new_sub_cat/(?P<cat>.*)$', 'forum.views.new_sub_cat'),
)


"""  url(r'^([^\r]*)[\/]([^\r]*)', 'forum.views.get_thread', {'category': r'$1', 'thread': r'$2'}),"""
