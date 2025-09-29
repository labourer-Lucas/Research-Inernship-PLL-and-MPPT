# TUM HLU Latex Template Git Repository

This repository is the TUM HLU Latex Template for thesis.
First git is briefly introduced, further down there are several comments on TeX. 

## What is Git?

Git is a distributed version control system that tracks changes in any set of computer files, usually used for coordinating work among programmers collaboratively developing source code during software development. Its goals include speed, data integrity, and support for distributed, non-linear workflows (thousands of parallel branches running on different systems).

## How to Install Git

Depending on your operating system, there are different ways to install git. Here are some common methods:

### Install Git on Windows

- Navigate to the latest [Git for Windows installer](https://git-scm.com/download/win) and download the latest version.
- Once the installer has started, follow the instructions as provided in the Git Setup wizard screen until the installation is complete.
- Open the windows command prompt (or Git Bash if you selected not to use the standard Git Windows Command Prompt during the Git installation).
- Type `git version` to verify Git was installed.

### Install Git on Linux

- If you want to install git on Linux via a binary installer, you can generally do so through your distribution's package management tool. For example:
  - If you're on Fedora (or any closely-related RPM-based distribution), use this command: `sudo dnf install git-all`.
  - If you're on a Debian-based distribution (such as Ubuntu), use this command: `sudo apt install git-all`.


## How to Fork a Repository

Forking a repository means creating a copy of an existing repository on your own account. You can fork any public repository by clicking the **Fork button** on  the **top right corner** of the **repository page**. This will lead you to the fork project page, there you can change the project name and namespace. Make sure to set the visibility level to private. This will create a new repository under your username with the **same name** and content as the **original one**. You can then clone your forked repository to your local machine and make changes to it. 


## How to Use This Repository and Commit Changes to It

To use this repository, you need to clone it to your local machine first. You can do this by running the following command in your terminal:

`git clone https://gitlab.lrz.de/your-username/hlu-thesis-template.git` 

This will create a new folder called hlu-thesis-template in your current directory with all the files and history of the repository.

To commit changes to this repository, you need to follow these steps:

- Make some changes to the files in your working tree (the folder where you cloned the repository).
- Add the changed files to the staging area using `git add` command. For example: `git add README.md`
- Commit the changes to your local repository using `git commit` command with a descriptive message. For example: `git commit -m "Update README.md"`
- Push the changes to your remote repository on GitHub using `git push` command. For example: `git push origin main`
- You can also use graphical tools or IDEs that support git operations if you prefer, popular options are for example SourceTree, GitHub Desktop, GitKraken, VSCode, TortoiseGit

For more information about git commands and workflows, please google it. 


<img src="https://imgs.xkcd.com/comics/git_2x.png" alt="Alt text" width="300"/>


<img src="https://imgs.xkcd.com/comics/git_commit_2x.png" alt="Alt text" width="500"/>



# LaTeX 
LaTeX is a text typesetting system based on TeX. Theses at HLU are written with LaTeX and versioned with Git and gitlab-lrz. 
A template is available for editing. LaTeX has to be learned by self-study, for which numerous tutorials are available. 
It is also important to ensure that illustrations are not used in the form of pixel graphics in the thesis, if possible, but that vector graphics are used. 
Suitable tools for creating vector graphics are Tikz and Inkscape. 
Common LaTeX editors are TeXstudio, Texmaker or Visual Studio Code. 

## LaTeX installation

Here is a starting point on how to install LaTeX locally on your computer. 
https://www.latex-project.org/get/#tex-distributions


## Creating beautiful figures with matlab2tikz 

To export figures from Matlab and include them into your tex project, matlab2tikz is highly recommended. Here are two nice examples on how to use it.

- https://tomlankhorst.nl/matlab-to-latex-with-matlab2tikz/
- https://www.sebastianjiroschlecht.com/post/matlab2tikz/
