FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    openjdk-21-jdk \
    make \
    git \
    curl \
    vim \
    nano \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /os_concept

COPY . .

CMD ["/bin/bash"]
