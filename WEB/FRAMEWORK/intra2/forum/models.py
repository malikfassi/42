from django.db import models
from django import forms
from django.contrib import admin

from auth.models import UserProfile
from django.contrib.auth.models import User

class CategoryAdmin(admin.ModelAdmin):
    list_display = ['title', 'parent']

class ThreadAdmin(admin.ModelAdmin):
    exclude = ('author',)
    list_display = ('title', 'message', 'category', 'author')

    def save_model(self, request, obj, form, change):
        obj.author = request.user
        obj.save()


# Create your models here.
class Category(models.Model):
    title = models.CharField(max_length=100, unique=True)
    parent = models.ForeignKey("Category", blank=True, null=True, default=None)
    class Meta:
        unique_together = ('title', 'parent')
    def __unicode__(self):
        return (self.title)

class Thread(models.Model):
    message = models.TextField(max_length=10000)
    title = models.CharField(max_length=140)
    author = models.ForeignKey(User)
    category = models.CharField(max_length=100)
    class Meta:
        unique_together = ('title', 'category')
    def __unicode__(self):
        return (self.title)

admin.site.register(Category, CategoryAdmin)
admin.site.register(Thread, ThreadAdmin)
"""

parent = models.ForeignKey("Category", blank=True, null=True, default=None)
"""