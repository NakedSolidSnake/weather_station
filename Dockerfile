FROM ubuntu

RUN apt-get update && apt-get install pip cmake g++ gdb uuid-dev -y

RUN pip install conan==1.59

WORKDIR /development

EXPOSE 8089
EXPOSE 8090

ENTRYPOINT [ "/bin/tail", "-f", "/dev/null" ]

