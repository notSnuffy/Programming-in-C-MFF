# Lab Assignments

Assignments for C++ labs https://gitlab.mff.cuni.cz/teaching/nprg041/drozdik/labs

## Workflow

First clone your work Gitlab repository from [group for this semester](https://gitlab.mff.cuni.cz/teaching/nprg041/2022-23/drozdik):
```
git clone git@gitlab.mff.cuni.cz:teaching/nprg041/2022-23/drozdik/<your_login>.git
```


Add this repository as another [git remote](https://git-scm.com/docs/git-remote).
```
git remote add assignments git@gitlab.mff.cuni.cz:teaching/nprg041/drozdik/labs-assignments.git
```

Update new assignments before each lab to your current branch:
```
git fetch assignments
git merge assignments/master
```
