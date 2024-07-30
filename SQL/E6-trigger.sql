CREATE OR REPLACE FUNCTION correct_insert() RETURNS TRIGGER AS $correct_insert$
BEGIN
    IF (new.salario IS NOT NULL OR new.cargo IS NOT NULL) THEN
        new.BoolFuncionario = true;
    ELSIF (new.salario IS NULL AND new.cargo IS NULL) THEN
        new.BoolFuncionario = false;
    END IF;
    IF (new.cpf IS NOT NULL OR new.telefone IS NOT NULL) THEN
        new.BoolCliente = true;
    ELSIF (new.cpf IS NULL AND new.telefone IS NULL) THEN
        new.BoolCliente = false;
    END IF;
    RETURN NEW;
END;
$correct_insert$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER insercao_correta
BEFORE INSERT OR UPDATE ON pessoa
FOR EACH ROW EXECUTE PROCEDURE correct_insert();