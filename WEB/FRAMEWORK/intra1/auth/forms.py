from django import forms
from django.contrib.auth.forms import UserCreationForm
from pprint import pprint
from auth.models import UserProfile
from time import sleep


class ConnexionForm(forms.Form):
    username = forms.CharField(label="Nom d'utilisateur", max_length=30)
    password = forms.CharField(label="Mot de passe", widget=forms.PasswordInput)

class RegistrationForm(UserCreationForm):
    email = forms.EmailField(max_length=75)
    subscribed = forms.BooleanField(required=False)

    class Meta:
        model = UserProfile
        fields = ("username", "email", "subscribed", "password1", "password2")

    def save(self, commit=True):
        user = super(RegistrationForm, self).save(commit=False)
        user.email = self.cleaned_data["email"]
        user.subscribed = self.cleaned_data["subscribed"]
        if commit:
            user.save()
        return user