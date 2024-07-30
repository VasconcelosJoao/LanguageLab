CREATE OR REPLACE FUNCTION total_overlap() RETURNS TRIGGER AS $total_overlap$
BEGIN
    IF(TG_OP='INSERT') THEN        
        INSERT INTO entidade_controladora (id_entidade, tipo) VALUES (new.id, 'funcionario');
    ELSIF(TG_OP='UPDATE') THEN
        UPDATE entidade_controladora SET tipo = 'cliente' WHERE id_entidade = new.id;

    END IF;


RETURN NEW;
END;
$total_overlap$ LANGUAGE plpgsql;



CREATE TRIGGER total_sobreposto
BEFORE INSERT OR UPDATE funcionario
FOR EACH ROW EXECUTE PROCEDURE total_overlap();