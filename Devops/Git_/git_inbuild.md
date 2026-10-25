# git configuration 
git config --global user.name "gtcoder27"
git config --global user.email "girish@gmail.com"


# flow of files 
Untracked file -> Modified -> staged -> commited 



# initialize new repo 
git init 

# show status for changes 
git status 

# clone git repository
git clone <repo_url>

### staging 
# stage specific file using file name or all files using dot (.) 
git add sample.txt
git add .

# unstage specific file using file name 
git rm --cached sample.txt

# commit with message 
git commit -m "added frontend features"

# Undo last commit 
git reset  [ same as -> git reset --mixed ]  
# Keeps all changes. Undoes the last commit. Everything is left in your staging area.
git reset --soft
# Keeps all changes. Undoes the last commit and unstages them. Changes are safely left in your local files.
git reset --mixed (Default)  
# Destroys all changes. Completely wipes out the last commit and all local modifications.
git reset --hard


# shows history what you have done till now 
git log
git log --oneline


# Lists all branches available
git branch 
git branch -a   (including remote branches as well)
# makes new branch
git branch branch1
# switch branch
git switch branch1     ||    git checkout branch1
# switch branch and make new branch if not available
git switch -c branch1  


# Merge branch1 to main
git checkout main
git merge branch1


# rename branch name
git branch -m branch1 br1

# to get the difference
git diff branch1 branch2


# stash -> temporary storage to store staged changes (used for without commit change to other branch) 
git stash save "any message"
git checkout "branch2"
git stash list               // lists all stash storage in form of list 
git stash apply stash@{0}     // Apply stash to current branch
git drop stash@{0}             // remove stash@{0}
git clear                   // remove all stash list



# unstage a file 
git restore --staged app.py

# unstage all files
git restore --staged .

# connect local repo to gitlab
git remote add origin "url"
git remote -v 

# Viewing merged/unmerged branches
git branch merged
git branch --no-merged

# deleting a branch 
git branch -d branch1       // only works if branch has been merged 
git branch -D branch1      // force delete even if not merged 
git push origin --delete <feature-branch>   // deleting a remote branch


# commits graph
git log --oneline --graph --all

















