# Operating Systems Concepts — Example Source Codes

This repository contains example source codes to complement the course **Operating Systems Concepts** by **Sarun Intakosum**.

## Contents

| Directory | Description |
|---|---|
| `fork/` | Process creation using `fork()`, `exec()`, and `waitpid()` |
| `pipe/` | Inter-process communication with pipes and `dup2()` |
| `pthread/` | POSIX threads (pthreads) creation and management |
| `pthread-semaphore/` | Thread synchronization using POSIX semaphores |
| `shared-memory/` | Shared memory IPC between processes |
| `signal/` | Signal handling and inter-process signaling |
| `file/` | File I/O examples |
| `Java-Thread/` | Java thread creation and lifecycle |
| `Java-Process/` | Java process management |
| `Java-Semaphore/` | Java semaphore-based synchronization |
| `Java-Synchronization/` | Java synchronized blocks and monitors |
| `from-socrative/` | In-class exercise examples |
| `simpleshell.sh` | Simple shell script example |

## Getting Started

### Prerequisites

- [Docker](https://www.docker.com/products/docker-desktop) installed and running

---

## Using the Docker Image

### Option 1 — Pull from Docker Hub (Recommended)

Pull the pre-built image directly from Docker Hub:

```bash
docker pull ajsarun/os_concept
```

Then tag it locally so the Dev Container config can find it:

```bash
docker tag ajsarun/os_concept os_concept
```

### Option 2 — Build Locally

Clone the repository and build the image yourself:

```bash
git clone https://github.com/ajsarun/os_course.git
cd os_course
docker build -t os_concept .
```

---

### Run a Container

Run interactively and drop into a bash shell:

```bash
docker run -it os_concept
```

To mount your local source codes into the container so edits are reflected immediately:

```bash
docker run -it -v $(pwd):/os_concept os_concept
```

### Compile and Run Examples

Inside the container, navigate to any directory and compile with `gcc` or `javac`:

```bash
# C example
cd /os_concept/fork
gcc fork_example.c -o fork_example
./fork_example

# Java example
cd /os_concept/Java-Thread
javac First.java
java First
```

---

## Working with VS Code Dev Containers

The repository includes a Dev Container configuration so you can develop directly inside the `os_concept` Docker image from VS Code, with full IntelliSense, a built-in terminal, and debugger support.

### Prerequisites

- [VS Code](https://code.visualstudio.com/)
- [Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) (`ms-vscode-remote.remote-containers`)
- [Docker](https://www.docker.com/products/docker-desktop) running
- `os_concept` image available locally (pull or build using the steps above)

### Steps

1. Clone this repository and open it in VS Code:
   ```bash
   git clone https://github.com/ajsarun/os_course.git
   code os_course
   ```

2. Make sure the `os_concept` image is available locally — pull it from Docker Hub:
   ```bash
   docker pull ajsarun/os_concept
   docker tag ajsarun/os_concept os_concept
   ```

3. When prompted, click **Reopen in Container** — or open the Command Palette (`F1`) and run:
   ```
   Dev Containers: Reopen in Container
   ```

4. VS Code will start a container from the `os_concept` image and install the following extensions automatically:
   - C/C++ IntelliSense & debugger
   - Java language support & debugger
   - Makefile tools

5. The workspace opens at `/os_concept` with all source codes ready to edit, compile, and run from the integrated terminal.

---

## Course

**Operating Systems Concepts**
Instructor: Sarun Intakosum
