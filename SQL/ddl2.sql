--Exemplo de especialização parcial exclusiva 1
-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY,
--     tipo VARCHAR(20),
--     nome VARCHAR(100),
--     endereco VARCHAR(200)
-- );

-- CREATE TABLE cliente (
--     id_cliente INT PRIMARY KEY REFERENCES pessoa(id),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20)
-- );

-- CREATE TABLE funcionario (
--     id_funcionario INT PRIMARY KEY REFERENCES pessoa(id),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50)
-- );

--Exemplo de especialização parcial sobreposta3
-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY,
--     nome VARCHAR(100)
-- );

-- CREATE TABLE cliente (
--     id_cliente INT PRIMARY KEY REFERENCES pessoa(id),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20)
-- );

-- CREATE TABLE funcionario (
--     id_funcionario INT PRIMARY KEY REFERENCES pessoa(id),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50)
-- );

-- CREATE TABLE pessoa_controller (
--     id_pessoa INT REFERENCES pessoa(id),
--     tipo VARCHAR(20),
--     PRIMARY KEY (id_pessoa, tipo) 
-- );

-- Exemplo de especialização parcial exclusiva 4
-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY,
--     nome VARCHAR(100),
--     tipo VARCHAR(20),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20)
-- );

-- Exemplo de especialização parcial sobreposta 6
-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY,
--     nome VARCHAR(100),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20),
--     boolFuncionario boolean,
--     boolCliente boolean
-- );

-- Exemplo de especialização total exclusiva 8
-- CREATE TABLE entidade_controladora (
--     id_entidade SERIAL PRIMARY KEY,
--     tipo VARCHAR(20)
-- );
-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY REFERENCES entidade_controladora(id_entidade),
--     nome VARCHAR(100),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20)
-- );


CREATE TABLE entidade_controladora (
    id SERIAL PRIMARY KEY,
    tipo VARCHAR(20)
);

-- Exemplo de especialização total sobreposta 9
CREATE TABLE cliente(
    id SERIAL PRIMARY KEY REFERENCES entidade_controladora(id),
    nome VARCHAR(100),
    cpf VARCHAR(11),
    telefone VARCHAR(20)
);

CREATE TABLE func(
    id SERIAL PRIMARY KEY REFERENCES entidade_controladora(id),
    nome VARCHAR(100),
    salario DECIMAL(10, 2),
    cargo VARCHAR(50)
);

