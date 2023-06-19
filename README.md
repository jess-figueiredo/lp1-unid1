# Como usar o Sistema de gerenciamento farmaceutico:
Este e um passo a passo de como ultilizar o sistema de gerenciamneto farmaceutico, mesmo que muito intuitivo todo sistema tem um manual, entao vamos la.


## Passo a passo área do Admin:
- O usuario deve digitar 2 para entrar neste modo.
- O sistema irá requisitar o login e senha para acessar o modo admin. Login//senha é admin//admin.
- Após inserir a senha será necessário adicionar remédios se o depósito(remédios.txt) estiver vazio ou não existir, digitando 1.


###  1 - Cadastrar remédio no depósito
1. O sistema irá requisitar o nome e o preço do produto a ser adicionado.
2. Após cadastrar, irá ser questionádo se o admin deseja adicionar outro remédio e poderá ser respondido sim com 'y', caso o sistema receba qualquer outro valor ele volta para o modo Admin e pedira novamente a senha caso o usuario ainda queira acessar alguma funcionalidade.
   
###  2 - Listar medicamentos e valores
1. O sistema ira retornar uma lista com todos os produtos cadastrados no sistemas e pedir a senha do admin para voltar ao menu inicial.

###  3 - Buscar produto cadastrado
1. Ao digitar o numero 3 nas opcoes do admin, o sistema ira requisitar um nome de um produto para verificar se ele foi cadastrado pelo admin.
2. O sistema retornara se o produto foi encontrado ou nao e perguntar se o usuario deseja buscar outro produto.
3. Apos isso, sera requisitado a senha do admin e direcionado ao menu admin.

###  4 - Atualizar o preco de um produto cadastrado
1. Ao digitar 4, sera necessario digitar o nome do produto ao qual sera atualizado o preco para ser verificado se ele foi cadastrado ou nao. Apos informar se existe na lista, o usuario tera que digitar um novo valor para o produto.
2. Ao finalizar a atualizacao o sistema ira perguntar se deseja atualizar o valor de outro produto.
3. Apos isso, sera requisitado a senha do admin e direcionado ao menu admin.
   
###  5 - Excluir produto cadastrado
1. Apos escolher esta opcao o usuario devera digitar o nome do produto a ser excluido para o sistema verificar se ele existe na lista.
2. Ao finalizar, o sistema ira perguntar se deseja excluir outro produto.
3. Apos isso, sera requisitado a senha do admin e direcionado ao menu admin.


## Passo a passo área do cliente:
- Para que o cliente possa usar as funcionalidades cridas algumas regras devem ser satisfeitas. Uma delas e que o admin tenha cadastrado produtos na area admin, finalizado o programa e comecado novamente.
- Finalemente, digitando 1 nas opcoes de acesso o usuario e direcionado a area cliente.

###  1 - Listar todos os medicamentos cadastrados.
1. Esta opcao ira retornar uma lista com todos os remedios disponiveis no sistema e carregar novamente todas as opcoes do cliente.

###  2 - Buscar remedio pelo nome
1. Esta funcionalidade permite ao cliente buscar um produto pelo seu nome para verificar se esta disponivel na lista.
2. Apos buscar, usuario tem a escolha de buscar outro ou sair da funcionalidade, sendo direcinado para o menu cliente.

###  3 - Selecionar produto para compra lo
1. Esta funcionalidade permite ao cliente buscar por um produto conhecido, o sistema ira verificar se ele esta disponivel, caso sim sera questionado ao cliente se ele deseja adiciona lo no carrinho de compras.
2.  usuario tem a escolha de adicionar outro ou sair da funcionalidade, sendo direcinado para o menu cliente.

###  4 - calcular o valor total da compra
1. Esta funcionalidade permite ao cliente verificar todos os produtos contidos no carrinho e o preco total a pagar.
2. O sistema ira retornar uma lista com remedios no carrinho com o total ao final,logo depois todas as opcoes da area do cliente.
   
###  5 - Excluir um medicamento do carrinho
1. A funcionalidade permite ao usuario excluir um ou mais remedios do carrinho. Sendo assim sera necessario informar o nome do produto a ser deletado e se tem certeza que o cliente deseja remove lo.
2. Sera questionado se quer deletar outro ou voltar ao menu cliente.

