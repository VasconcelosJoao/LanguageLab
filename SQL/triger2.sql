CREATE OR REPLACE FUNCTION credit_checker() RETURNS TRIGGER AS $credit_checker$
DECLARE
    total INT;
BEGIN
    SELECT SUM(d.ncred) INTO total
    FROM matricula m
    JOIN disciplina d on m.sigla = d.sigla
    WHERE m.nmatr = NEW.nmatr;

    IF total + (SELECT ncred FROM disciplina WHERE sigla = new.sigla) > 20 THEN
        RAISE EXCEPTION 'Limite de créditos excedido';
    END IF;
    RETURN NEW;
END;
$credit_checker$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER verificador_de_creditos
BEFORE INSERT ON matricula
FOR EACH ROW EXECUTE PROCEDURE credit_checker();