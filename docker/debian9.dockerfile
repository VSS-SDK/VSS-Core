FROM debian:9

# Instala Base
RUN apt-get update
RUN apt-get install -y python-pip python-dev

# Instala Ansible
RUN pip install ansible==2.7.8.0

# Copia tudo para o container
COPY . /vss-core-debian9
WORKDIR /vss-core-debian9

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-core-debian9/configure.sh
RUN chmod +x /vss-core-debian9/entrypoint.sh
RUN chmod +x /vss-core-debian9/scripts/protos.sh
RUN chmod +x /vss-core-debian9/scripts/base.sh

# Executa a instalação na criação dos containers
RUN /vss-core-debian9/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-core-debian9/entrypoint.sh"]