UPDATE pessoa SET salario=NULL,Cargo=NULL, cpf = NULL, telefone = NULL WHERE id = 6;

-- INSERT INTO pessoa (id,nome,salario,cargo,cpf,telefone) VALUES
-- (1,'joao',1000,'gerente',NULL,NULL),
-- (2,'maria',NULL,NULL,'12345678901','123456789'),
-- (3,'pedro',NULL,NULL,'12345678902','123456780'),
-- (4,'joana',NULL,NULL,'12345678903','123456781'),
-- (5,'carlos',NULL,NULL,'12345678904','123456782'),
-- (6,'ana',NULL,NULL,'12345678905','123456783');





-- CREATE TABLE pessoa (
--     id SERIAL PRIMARY KEY,
--     nome VARCHAR(100),
--     salario DECIMAL(10, 2),
--     cargo VARCHAR(50),
--     cpf VARCHAR(11),
--     telefone VARCHAR(20)
-- );

-- CREATE TABLE entidade_controladora (
--     id_entidade INT REFERENCES pessoa(id),
--     tipo VARCHAR(20),
--     PRIMARY KEY (id_entidade)
-- );
