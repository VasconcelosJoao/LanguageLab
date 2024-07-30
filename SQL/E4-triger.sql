CREATE OR REPLACE FUNCTION correct_insert() RETURNS TRIGGER AS $correct_insert$
BEGIN
IF(TG_OP = 'INSERT') THEN
    IF NEW.tipo = 'funcionario' and (new.cpf IS NOT NULL OR new.telefone IS NOT NULL) THEN
        RAISE EXCEPTION 'Ococorreu uma tentavida de inserir dados de cliente em um funcionario';
    ELSIF NEW.tipo = 'cliente' and (new.salario IS NOT NULL OR new.cargo IS NOT NULL) THEN
        RAISE EXCEPTION 'Ococorreu uma tentavida de inserir dados de funcionario em um cliente';
    END IF;
ELSIF(TG_OP = 'UPDATE') THEN
    IF NEW.tipo = 'funcionario' and ((old.cpf IS NOT NULL OR old.telefone IS NOT NULL) AND (new.cpf IS NOT NULL OR new.telefone IS NOT NULL)) THEN
        RAISE EXCEPTION 'Ococorreu uma tentavida de inserir dados de cliente em um funcionario';
    ELSIF NEW.tipo = 'cliente' and ((old.salario IS NOT NULL OR old.cargo IS NOT NULL) AND (new.salario IS NOT NULL OR new.cargo IS NOT NULL)) THEN
        RAISE EXCEPTION 'Ococorreu uma tentavida de inserir dados de funcionario em um cliente';
    END IF;
END IF;     

    RETURN NEW;
END;
$correct_insert$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER insercao_correta
BEFORE INSERT OR UPDATE ON pessoa
FOR EACH ROW EXECUTE PROCEDURE correct_insert();
