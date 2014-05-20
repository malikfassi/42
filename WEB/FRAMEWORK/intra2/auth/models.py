from django.contrib.auth.models import User
from django.db import models
from django.contrib.auth.models import UserManager
from django.contrib import admin


class UserProfile(User):
	subscribed = models.BooleanField()
	objects = UserManager()

admin.site.register(UserProfile)

