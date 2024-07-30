CREATE OR REPLACE FUNCTION total_exclusive() RETURNS TRIGGER AS $total_exclusive$
BEGIN
    IF(TG_OP='INSERT') THEN        
        IF (new.salario IS NULL AND new.cargo IS NULL AND NEW.cpf IS NULL AND NEW.telefone IS NULL) THEN
            RAISE EXCEPTION 'Erro: não foi possivel realizar a operação, pois a pessoa não possui cargo';
        ELSIF ((new.salario is NOT NULL OR NEW.cargo is NOT NULL)AND (NEW.cpf IS NOT NULL OR NEW.telefone IS NOT NULL)) THEN
            RAISE EXCEPTION 'Erro: não foi possivel realizar a operação, pois a pessoa tem caracteristicas de dois cargos';
        ELSIF (new.salario IS NOT NULL OR new.cargo IS NOT NULL) THEN
            INSERT INTO entidade_controladora (id_entidade, tipo) VALUES (new.id, 'funcionario');
        ELSIF (NEW.cpf IS NOT NULL OR NEW.telefone IS NOT NULL) THEN
            INSERT INTO entidade_controladora (id_entidade, tipo) VALUES (new.id, 'cliente');
        END IF;
        RETURN NEW;
    ELSIF(TG_OP='UPDATE') THEN
        IF (new.salario IS NULL AND new.cargo IS NULL AND NEW.cpf IS NULL AND NEW.telefone IS NULL) THEN
            RAISE EXCEPTION 'Erro: não foi possivel realizar a operação, pois a pessoa não pode possuir mais de cargo';
        ELSIF ((new.salario is NOT NULL OR NEW.cargo is NOT NULL)AND (NEW.cpf IS NOT NULL OR NEW.telefone IS NOT NULL)) THEN
            RAISE EXCEPTION 'Erro: não foi possivel realizar a operação, pois a pessoa tem caracteristicas de dois cargos';
        ELSIF (new.salario IS NOT NULL OR new.cargo IS NOT NULL) THEN
            UPDATE entidade_controladora SET tipo = 'funcionario' WHERE id_entidade = new.id;
        ELSIF (NEW.cpf IS NOT NULL OR NEW.telefone IS NOT NULL) THEN
            UPDATE entidade_controladora SET tipo = 'cliente' WHERE id_entidade = new.id;
        END IF;
    END IF;
    RETURN NEW;
END;
$total_exclusive$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER total_exclusiva
BEFORE INSERT OR UPDATE ON pessoa
FOR EACH ROW EXECUTE PROCEDURE total_exclusive();




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
