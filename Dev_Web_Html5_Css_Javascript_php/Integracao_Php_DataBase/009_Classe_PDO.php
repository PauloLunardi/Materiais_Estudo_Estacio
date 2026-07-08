/*
=========================================================
CLASSE PDO (PHP Data Objects)
=========================================================

A classe PDO é responsável por criar e gerenciar
a conexão entre uma aplicação PHP e um banco de dados.

Além de estabelecer a conexão, ela fornece métodos
para executar consultas, controlar transações,
obter informações sobre erros e configurar
o comportamento da conexão.

=========================================================
*/

PDO {

    /*
    -----------------------------------------------------
    __construct()

    Construtor da classe PDO.

    Cria uma nova conexão com o banco de dados.

    Parâmetros:

    $dsn      -> String de conexão (Driver + Banco)
    $username -> Usuário do banco
    $passwd   -> Senha
    $options  -> Configurações adicionais (opcional)

    Exemplo:

    new PDO($dsn, $usuario, $senha);
    -----------------------------------------------------
    */

    public __construct (
        string $dsn,
        string $username,
        string $passwd,
        array $options
    );


    /*
    -----------------------------------------------------
    beginTransaction()

    Inicia uma transação.

    Todas as operações realizadas após este método
    somente serão gravadas no banco caso seja chamado
    commit().

    Retorna:
    true ou false
    -----------------------------------------------------
    */

    public beginTransaction() : bool;


    /*
    -----------------------------------------------------
    commit()

    Confirma todas as alterações realizadas
    durante uma transação.

    Equivale ao comando SQL COMMIT.

    Retorna:
    true ou false
    -----------------------------------------------------
    */

    public commit() : bool;


    /*
    -----------------------------------------------------
    errorCode()

    Retorna apenas o código do último erro ocorrido.

    Exemplo:

    23000
    -----------------------------------------------------
    */

    public errorCode() : string;


    /*
    -----------------------------------------------------
    errorInfo()

    Retorna informações completas sobre o último erro.

    O retorno é um array contendo:

    Código SQLSTATE
    Código específico do driver
    Mensagem detalhada

    Muito útil durante a depuração.
    -----------------------------------------------------
    */

    public errorInfo() : array;


    /*
    -----------------------------------------------------
    exec()

    Executa comandos SQL que NÃO retornam registros.

    Muito utilizado com:

    INSERT
    UPDATE
    DELETE

    Retorna:

    Número de linhas afetadas.
    -----------------------------------------------------
    */

    public exec(string $statement) : int;


    /*
    -----------------------------------------------------
    getAttribute()

    Obtém uma configuração atual da conexão PDO.

    Exemplo:

    Driver utilizado
    Versão do servidor
    Tipo do banco

    Retorna diversos tipos de informação.
    -----------------------------------------------------
    */

    public getAttribute(int $attribute) : mixed;


    /*
    -----------------------------------------------------
    getAvailableDrivers()

    Método estático.

    Lista todos os drivers PDO instalados.

    Exemplo de retorno:

    mysql
    pgsql
    sqlite
    sqlsrv
    -----------------------------------------------------
    */

    public static getAvailableDrivers() : array;


    /*
    -----------------------------------------------------
    inTransaction()

    Verifica se existe uma transação aberta.

    Retorna:

    true  -> existe transação

    false -> não existe
    -----------------------------------------------------
    */

    public inTransaction() : bool;


    /*
    -----------------------------------------------------
    lastInsertId()

    Retorna o ID do último registro inserido.

    Muito usado após INSERT em tabelas
    com AUTO_INCREMENT ou SERIAL.

    Exemplo:

    INSERT INTO pessoas...

    retorna:

    15
    -----------------------------------------------------
    */

    public lastInsertId(string $name = NULL) : string;


    /*
    -----------------------------------------------------
    prepare()

    Prepara uma consulta SQL.

    É o método mais recomendado,
    pois protege contra SQL Injection.

    Depois de preparar a consulta,
    utiliza-se execute().

    Exemplo:

    SELECT * FROM pessoas WHERE id = ?

    Retorna um objeto PDOStatement.
    -----------------------------------------------------
    */

    public prepare(
        string $statement,
        array $driver_options = array()
    ) : PDOStatement;


    /*
    -----------------------------------------------------
    query()

    Executa diretamente uma consulta SQL.

    Muito utilizada em SELECT simples.

    Retorna um objeto PDOStatement.
    -----------------------------------------------------
    */

    public query(string $statement) : PDOStatement;


    /*
    -----------------------------------------------------
    quote()

    Coloca aspas corretamente em uma string.

    Também realiza o escape de caracteres.

    Exemplo:

    João

    torna-se

    'João'

    Ajuda na segurança das consultas.
    -----------------------------------------------------
    */

    public quote(
        string $string,
        int $parameter_type = PDO::PARAM_STR
    ) : string;


    /*
    -----------------------------------------------------
    rollBack()

    Cancela uma transação.

    Todas as alterações realizadas após
    beginTransaction() são desfeitas.

    Equivale ao SQL ROLLBACK.
    -----------------------------------------------------
    */

    public rollBack() : bool;


    /*
    -----------------------------------------------------
    setAttribute()

    Configura propriedades da conexão.

    O uso mais comum é ativar
    o tratamento de exceções.

    Exemplo:

    $pdo->setAttribute(
        PDO::ATTR_ERRMODE,
        PDO::ERRMODE_EXCEPTION
    );

    Retorna:

    true ou false
    -----------------------------------------------------
    */

    public setAttribute(
        int $attribute,
        mixed $value
    ) : bool;

}
