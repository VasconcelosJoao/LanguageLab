CREATE OR REPLACE FUNCTION idade_definer() RETURNS TRIGGER AS $idade_definer$
BEGIN
    NEW.idade = EXTRACT(YEAR FROM AGE(NEW.datanasc));
    RETURN NEW;
END;
$idade_definer$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER define_idade
BEFORE INSERT ON aluno
FOR EACH ROW EXECUTE PROCEDURE idade_definer();