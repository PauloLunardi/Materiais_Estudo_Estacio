<?php

 $var1 = 10;
 $var2 = 10;

 if($var1 > $var2):
	echo "$var1 é maior que $var2";
 elseif($var1 < $var2):
	echo "$var1 é menor que $var2";
 else:
	echo "$var1 e $var2 são iguais";
 endif;

// PHP permite que sejam utilizadas formas alternativas das instruções vistas. 
// Em linhas gerais, troca-se a chave de abertura por dois pontos e a de fechamento pela palavra reservada “end” seguida do nome da instrução.
