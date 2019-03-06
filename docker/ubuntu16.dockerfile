FROM ubuntu:16.04

# Instala Base
RUN apt-get update
RUN apt-get install -y python-pip python-dev

# Instala Ansible
RUN pip install ansible==2.7.8.0

# Copia tudo para o container
COPY . /vss-core-ubuntu16
WORKDIR /vss-core-ubuntu16

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-core-ubuntu16/configure.sh
RUN chmod +x /vss-core-ubuntu16/entrypoint.sh
RUN chmod +x /vss-core-ubuntu16/scripts/protos.sh
RUN chmod +x /vss-core-ubuntu16/scripts/base.sh

# Executa a instalação na criação dos containers
RUN /vss-core-ubuntu16/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-core-ubuntu16/entrypoint.sh"]