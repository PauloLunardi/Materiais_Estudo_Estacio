/*
=========================================================
CLASSE PDOStatement
=========================================================

A classe PDOStatement representa uma instrução SQL
(preparada ou executada) através do PDO.

Ela é retornada principalmente pelos métodos:

- prepare()
- query()

É através desta classe que executamos consultas,
recuperamos registros, vinculamos parâmetros e
manipulamos os resultados obtidos do banco de dados.

=========================================================
*/

PDOStatement implements Traversable {

    /*
    -----------------------------------------------------
    PROPRIEDADE

    queryString

    Armazena a instrução SQL utilizada
    para criar o objeto PDOStatement.

    Exemplo:

    SELECT * FROM pessoas
    -----------------------------------------------------
    */

    readonly string $queryString;


    /*
    =====================================================
    MÉTODOS
    =====================================================
    */


    /*
    -----------------------------------------------------
    bindColumn()

    Associa uma coluna retornada pela consulta
    diretamente a uma variável PHP.

    Muito utilizado quando desejamos armazenar
    automaticamente os valores retornados.

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public bindColumn(
        mixed $column,
        mixed &$param,
        int $type,
        int $maxlen,
        mixed $driverdata
    ) : bool;


    /*
    -----------------------------------------------------
    bindParam()

    Associa uma variável a um parâmetro da consulta.

    A variável é vinculada por referência.

    Muito utilizado em consultas preparadas.

    Exemplo:

    WHERE id = :id

    bindParam(":id", $id);

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public bindParam(
        mixed $parameter,
        mixed &$variable,
        int $data_type = PDO::PARAM_STR,
        int $length,
        mixed $driver_options
    ) : bool;


    /*
    -----------------------------------------------------
    bindValue()

    Semelhante ao bindParam().

    Entretanto, associa diretamente um valor,
    e não uma variável.

    Exemplo:

    bindValue(":nome", "João");

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public bindValue(
        mixed $parameter,
        mixed $value,
        int $data_type = PDO::PARAM_STR
    ) : bool;


    /*
    -----------------------------------------------------
    closeCursor()

    Libera os recursos utilizados pela consulta.

    Permite executar outra consulta utilizando
    o mesmo objeto PDOStatement.

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public closeCursor() : bool;


    /*
    -----------------------------------------------------
    columnCount()

    Retorna a quantidade de colunas
    existentes no resultado da consulta.

    Exemplo:

    SELECT id, nome, idade

    Resultado:

    3
    -----------------------------------------------------
    */

    public columnCount() : int;


    /*
    -----------------------------------------------------
    debugDumpParams()

    Exibe informações sobre os parâmetros
    utilizados na consulta preparada.

    Muito útil durante a depuração (debug).

    Não retorna valor.
    -----------------------------------------------------
    */

    public debugDumpParams() : void;


    /*
    -----------------------------------------------------
    errorCode()

    Retorna o código do último erro ocorrido
    durante a execução da consulta.
    -----------------------------------------------------
    */

    public errorCode() : string;


    /*
    -----------------------------------------------------
    errorInfo()

    Retorna informações detalhadas
    sobre o último erro ocorrido.

    O retorno é um array contendo:

    SQLSTATE
    Código do driver
    Mensagem de erro
    -----------------------------------------------------
    */

    public errorInfo() : array;


    /*
    -----------------------------------------------------
    execute()

    Executa uma consulta preparada.

    É chamado após prepare().

    Exemplo:

    $stmt->execute();

    ou

    $stmt->execute([
        ":id" => 10
    ]);

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public execute(
        array $input_parameters = NULL
    ) : bool;


    /*
    -----------------------------------------------------
    fetch()

    Retorna apenas UM registro da consulta.

    Cada chamada retorna a próxima linha.

    Muito utilizado dentro de loops.

    Retorna:

    Um registro ou false.
    -----------------------------------------------------
    */

    public fetch(
        int $fetch_style,
        int $cursor_orientation,
        int $cursor_offset
    ) : mixed;


    /*
    -----------------------------------------------------
    fetchAll()

    Retorna TODOS os registros
    da consulta em um array.

    Muito utilizado quando desejamos
    carregar todos os dados de uma vez.

    Retorna:

    Array contendo todas as linhas.
    -----------------------------------------------------
    */

    public fetchAll(
        int $fetch_style,
        mixed $fetch_argument,
        array $ctor_args
    ) : array;


    /*
    -----------------------------------------------------
    fetchColumn()

    Retorna apenas o valor
    de uma coluna específica.

    Exemplo:

    SELECT nome

    Resultado:

    João
    -----------------------------------------------------
    */

    public fetchColumn(
        int $column_number = 0
    ) : mixed;


    /*
    -----------------------------------------------------
    fetchObject()

    Retorna cada registro
    como um objeto.

    Caso nenhuma classe seja informada,
    utiliza stdClass.

    Muito útil em aplicações orientadas
    a objetos.
    -----------------------------------------------------
    */

    public fetchObject(
        string $class_name = "stdClass",
        array $ctor_args
    ) : mixed;


    /*
    -----------------------------------------------------
    getAttribute()

    Obtém uma configuração específica
    do PDOStatement.

    Retorna diversos tipos de informação.
    -----------------------------------------------------
    */

    public getAttribute(
        int $attribute
    ) : mixed;


    /*
    -----------------------------------------------------
    getColumnMeta()

    Obtém informações sobre uma coluna.

    Exemplos:

    Nome da coluna
    Tipo
    Tamanho
    -----------------------------------------------------
    */

    public getColumnMeta(
        int $column
    ) : array;


    /*
    -----------------------------------------------------
    nextRowset()

    Avança para o próximo conjunto
    de resultados.

    Utilizado principalmente quando
    Stored Procedures retornam
    múltiplos resultados.
    -----------------------------------------------------
    */

    public nextRowset() : bool;


    /*
    -----------------------------------------------------
    rowCount()

    Retorna a quantidade de linhas
    afetadas pela consulta.

    Muito utilizado em:

    INSERT
    UPDATE
    DELETE

    Em SELECT seu comportamento
    depende do driver utilizado.
    -----------------------------------------------------
    */

    public rowCount() : int;


    /*
    -----------------------------------------------------
    setAttribute()

    Configura propriedades
    específicas do PDOStatement.

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public setAttribute(
        int $attribute,
        mixed $value
    ) : bool;


    /*
    -----------------------------------------------------
    setFetchMode()

    Define como os registros serão
    retornados pelo fetch().

    Exemplos:

    PDO::FETCH_ASSOC

    PDO::FETCH_OBJ

    PDO::FETCH_NUM

    PDO::FETCH_CLASS

    Retorna:

    true ou false.
    -----------------------------------------------------
    */

    public setFetchMode(
        int $mode
    ) : bool;

}
