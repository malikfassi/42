from django import forms
from forum.models import Thread, Category

def get_all_parent_category():
    allcat = Category.objects.filter(parent=None)
    return (allcat)

class ThreadForm(forms.ModelForm):
    class Meta:
        model = Thread
        exclude = ('category',)
        fields = ['title', 'message']

class CategoryForm(forms.ModelForm):
    class Meta:
        model = Category
        fields = ['title']