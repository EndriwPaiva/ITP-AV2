# ITP-AV2
Avaliação 2 de itp 

 Endriw Paiva de Oliveira // opção 1
 Descrição:
  Problema que o programa resolve: Problema: uma pessoa precisa registrar três notas de cada estudante e obter um resumo dos resultados
  da turma.

• Compilação e execução: Qualquer meio de execução. No meu caso tive que ir ate a pasta onde ele ta, então usei cd Documents/codigos
Após isso, utilizei:
gcc codigos.c -o codigos
./codigos

utilizar o inicializador do VScode funciona também.

O codigo em si vai pedir o numero de estudantes (tem que ser entre 1 e 10) e por estudante vai pedir nome e 3 notas, que serão digitadas separadamente.

• Testes: 
  1 correto:
entradas:

3
yunara
6
7
10
miau miau
4
3
2
ronova
10
10
10

saída:
Nome            | Nota 1 Nota 2 Nota 3 | Media  | Situacao

yunara          |    6.0    7.0   10.0 |    7.7 | atingiu a meta
miau miau       |    4.0    3.0    2.0 |    3.0 | abaixo da meta
ronova          |   10.0   10.0   10.0 |   10.0 | atingiu a meta

Media geral da turma: 6.89
Estudante(s) com a maior media (10.00):
- Ronova

  2 erro:
entradas:
11

saida:
Quantidade invalida! Deve ser entre 1 e 10.
Digite a quantidade de estudantes (1 a 10): 

link do youtube (também estará no envio no sigaa): https://youtu.be/oLRZs7QLjDI

Referências: 
inicialização do codigo esta mais acima do readme.
