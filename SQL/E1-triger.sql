CREATE OR REPLACE FUNCTION triger_funcionario() RETURNS TRIGGER AS $triger_funcionario$
BEGIN 
    IF (SELECT id_cliente FROM cliente WHERE id_cliente = NEW.id_funcionario) IS NOT NULL THEN 
        RAISE EXCEPTION 'Pessoa já existe como cliente';
    END IF;
RETURN NEW;
END;
$triger_funcionario$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER triger_funcionario 
BEFORE INSERT ON funcionario 
FOR EACH ROW EXECUTE PROCEDURE triger_funcionario();

CREATE OR REPLACE FUNCTION triger_cliente() RETURNS TRIGGER AS $triger_cliente$
BEGIN 
    IF (SELECT id_funcionario FROM funcionario WHERE id_funcionario = NEW.id_cliente) IS NOT NULL THEN 
        RAISE EXCEPTION 'Pessoa já existe como Funcionario';
    END IF;
RETURN NEW;
END;
$triger_cliente$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER triger_cliente 
BEFORE INSERT ON cliente 
FOR EACH ROW EXECUTE PROCEDURE triger_cliente();

