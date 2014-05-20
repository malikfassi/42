from django.contrib.auth.models import User
from django.db import models
from django.contrib.auth.models import UserManager

class UserProfile(User):
	subscribed = models.BooleanField()
	objects = UserManager()