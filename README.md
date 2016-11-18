# Rede Social para Economia Compartilhada

O sistema implementa uma rede social que pode ser utilizada para economia compartilhada.

### A rede social é composta de:

a) Um grafo que modela a rede social:

a.1) Neste grafo cada pessoa é um vértice. Ele contém as seguintes informações sobre cada pessoa:

     Nome, gênero, idade, nível educacional, CEP, Interesses, 
     Transações: transações das quais participou e quais estão em andamento
     
a.2) As arestas representam quais pessoas são amigas ou não. Para que duas pessoas A e B sejam consideradas amigas é necessário uma aresta de A para B indicando que A é amiga de B e uma aresta de B para A indicando que B é amiga de A. O grau de separação entre duas pessoas é o número mínimo de arestas que separa duas pessoas.

a.3) A interface permite ao usuário:

    Criar pessoa, Editar pessoa, todos os dados inclusive amizades Excluir pessoa, 
    Fazer uma transação pedindo os requisitos
    
a.4) A interface para o administrador do sistema possibilita:

    A visualização das informações das pessoas através de um grafo. 
    Apresentar cada pessoas e suas relações. 
    Mostrar todos os vértices e arestas.
    Cadastrar e descadastrar transações. 
    Apresentar todas as transações feitas.
    
b) Leitor e escritor da rede social:
    Deve ser possível salvar e recuperar todas as informações sobre a rede social em um arquivo.
    
c) Funcionamento da economia compartilhada:

    Cada pessoa pode ter interesse em um produto ou serviço compartilhado. 
    Estes produtos ou serviços quando vendidos, alugados, etc, podem virar transações.
    
    Um usuário pode solicitar uma transação. Ele pode escolher uma dentro de uma lista cadastrada. Por exemplo, ele 
    escolheu pedir uma carona. O usuário pode escolher alguns requisitos sobre com quem quer pegarccarona. Estes 
    requisitos podem ser qualquer dado do usuário inclusive já ter participado deste tipo de transação anteriormente 
    e avaliação. Além disto, o usuário pode escolher qual o grau de separação ele quer o serviço. Por exemplo, aceita 
    carona de amigos, de amigos de amigos, qualquer um, etc.
    
    Todos os usuários que atendem aos requisitos são notificados a respeito do pedido de carona. Os usuários que 
    aceitaram a notificação dando carona são mostrados para o usuário que pediu a carona ordenados por avaliação 
    (se houver). Se o usuário que fez o pedido concordar, depois da transação concluída, todos os usuários envolvidos 
    fazem avaliação uns dos outros.
