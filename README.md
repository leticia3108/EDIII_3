# Trabalho Prático I
### Estrutura de dados III - USP São Carlos

# Resumo do trabalho

Serão fornecidos alguns arquivos, dentro deles alguns ```.csv``` e outros ```.bin```. Os .csv serão um mini banco de dados com algumas informações sobre dinissauros, como a sua especie, sua dieta, seu país de origem e etc. Os arquivos binários serão executáveis enviados pelo professor que terão determinadas entradas e saídas em conversa com o código feito no trabalho.

O código deverá ser feito em C, ter 6 funcionalidades e 9 restrições que serão mostradas a seguir.

# Funcionalidades:

## Fucnioanalidade 1

Permita a leitura de vários registros obtidos a partir de um arquivo de entrada
no formato csv e a gravação desses registros em um arquivo de dados de saída. O
arquivo de entrada no formato csv é fornecido juntamente com a especificação do
projeto, enquanto o arquivo de dados de saída deve ser gerado de acordo com as
especificações deste trabalho prático. O arquivo de dados de entrada não contém
registros removidos. Antes de terminar a execução da funcionalidade, deve ser
utilizada a função binarioNaTela, disponibilizada na página do projeto da disciplina,
para mostrar a saída do arquivo binário.


## Fucnioanalidade 2

Permita a recuperação dos dados de todos os registros armazenados em um
arquivo de dados de entrada, mostrando os dados de forma organizada na saída padrão
para permitir a distinção dos campos e registros. O tratamento de ‘lixo’ deve ser feito
de forma a permitir a exibição apropriada dos dados. Registros marcados como
logicamente removidos não devem ser exibidos. O arquivo de dados de entrada deve
ser percorrido apropriadamente.


## Fucnioanalidade 3

Permita a recuperação dos dados de todos os registros de um arquivo de dados
de entrada, de forma que esses registros satisfaçam um critério de busca determinado
pelo usuário. Qualquer campo pode ser utilizado como forma de busca.
Adicionalmente, apenas um campo pode ser utilizado na busca. Por exemplo, é
possível realizar a busca considerando somente o campo nome ou somente o campo
especie. Esta funcionalidade pode retornar 0 registros (quando nenhum satisfaz ao
critério de busca), 1 registro (quando apenas um satisfaz ao critério de busca), ou
vários registros. A funcionalidade [3] deve ser executada n vezes seguidas. Em
situações nas quais um determinado critério de busca não seja satisfeito, ou seja, caso a
solicitação do usuário não retorne nenhum registro a ser buscado, o programa deve
continuar a executar as buscas até completar as n vezes seguidas. Os valores dos
campos do tipo string devem ser especificados entre aspas duplas ("). Para a
manipulação de strings com aspas duplas, pode-se usar a função scan_quote_string
disponibilizada na página do projeto da disciplina. Registros marcados como
logicamente removidos não devem ser exibidos. O arquivo de dados de entrada deve
ser percorrido apropriadamente. Quando encontrado um campo que é único,
interrompe-se a busca específica.


## Fucnioanalidade 4

Permita a remoção lógica de registros em um arquivo de dados de entrada,
baseado na abordagem dinâmica de reaproveitamento de espaços de registros
logicamente removidos. A implementação dessa funcionalidade deve ser realizada
usando o conceito de lista de registros logicamente removidos, e deve seguir
estritamente a matéria apresentada em sala de aula. Como o arquivo possui registros de
tamanho fixo, a lista deve ser implementada como uma pilha. Os registros a serem
removidos devem ser aqueles que satisfaçam um critério de busca determinado pelo
usuário, de acordo com a especificação da funcionalidade [3]. Note que qualquer
campo pode ser utilizado como forma de remoção. Esta funcionalidade pode remover
0 registros (quando nenhum satisfaz ao critério de busca), 1 registro (quando apenas
um satisfaz ao critério de busca), ou vários registros (quando vários satisfazem ao
critério de busca). Ao se remover um registro, os valores dos bytes referentes aos
campos já armazenados no registro devem ser preenchidos com o caractere ‘$’, ou
seja, com lixo, com exceção dos valores dos campos de controle. A funcionalidade [4]
deve ser executada n vezes seguidas. Em situações nas quais um determinado critério
de busca não seja satisfeito, ou seja, caso a solicitação do usuário não retorne nenhum
registro a ser removido, o programa deve continuar a executar as remoções até
completar as n vezes seguidas. Antes de terminar a execução da funcionalidade, deve
ser utilizada a função binarioNaTela, disponibilizada na página do projeto da
disciplina, para mostrar a saída do arquivo binário de dados.

## Fucnioanalidade 5

Permita a inserção de novos registros em um arquivo de dados de entrada de
um determinado tipo, baseado na abordagem dinâmica de reaproveitamento de
espaços de registros logicamente removidos. A implementação dessa funcionalidade
deve ser realizada usando o conceito de lista de registros logicamente removidos, e
deve seguir estritamente a matéria apresentada em sala de aula. Como o arquivo possui
registros de tamanho fixo, a lista deve ser implementada como uma pilha. O lixo que
permanece no registro logicamente removido e que é reutilizado deve ser identificado
pelo caractere ‘$’. Na entrada desta funcionalidade, os dados são referentes aos
seguintes campos, na seguinte ordem: nome, dieta, habitat, populacao, tipo,
velocidade, medidaVelocidade, tamanho, especie, alimento. Campos com valores
nulos, na entrada da funcionalidade, devem ser identificados com NULO. Os valores
dos campos do tipo string devem ser especificados entre aspas duplas ("). Para a
manipulação de strings com aspas duplas, pode-se usar a função scan_quote_string
disponibilizada na página do projeto da disciplina. A funcionalidade [5] deve ser
executada n vezes seguidas. Antes de terminar a execução da funcionalidade, deve ser
utilizada a função binarioNaTela, disponibilizada na página do projeto da disciplina,
para mostrar a saída do arquivo de dados binário.

## Fucnioanalidade 6

Permita a compactação eficiente (desfragmentação) do arquivo de dados. A
compactação elimina os registros removidos, deixando no arquivo de dados somente
os registros marcados como não removidos. A compactação não deve eliminar o lixo,
ou seja, não deve eliminar o caractere ‘$’. Como entrada dessa funcionalidade, tem-se
um arquivo de dados binário que pode conter (ou não) registros logicamente
removidos. Como saída, tem-se um arquivo de dados binário sem registros marcados
como removidos. Antes de terminar a execução da funcionalidade, deve ser utilizada a
função binarioNaTela, disponibilizada na página do projeto da disciplina, para mostrar
a saída do arquivo binário.


# Restrições:

## Restrição 1
## Restrição 2
## Restrição 3
## Restrição 4
## Restrição 5
## Restrição 6
## Restrição 7
## Restrição 8
## Restrição 9