CREATE OR REPLACE FUNCTION registrador_tipoF() RETURNS TRIGGER AS $registrador_tipoF$
BEGIN
    INSERT INTO pessoa_controller (id_pessoa, tipo) VALUES (NEW.id_funcionario, 'funcionario');
    RETURN NEW;
END;
$registrador_tipoF$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER registrador_tipoF 
BEFORE INSERT ON funcionario
FOR EACH ROW EXECUTE PROCEDURE registrador_tipoF();

CREATE OR REPLACE FUNCTION registrador_tipoC() RETURNS TRIGGER AS $registrador_tipoC$
BEGIN
    INSERT INTO pessoa_controller (id_pessoa, tipo) VALUES (NEW.id_cliente, 'cliente');
    RETURN NEW;
END;
$registrador_tipoC$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER registrador_tipoC 
BEFORE INSERT ON cliente
FOR EACH ROW EXECUTE PROCEDURE registrador_tipoC();
