CREATE OR REPLACE FUNCTION avg_grade() RETURNS TRIGGER AS $avg_grade$ BEGIN
UPDATE disciplina
SET nota_media = (
        SELECT AVG(nota)
        FROM matricula m
            JOIN disciplina d on m.sigla = d.sigla
        WHERE m.sigla = NEW.sigla
    )
WHERE disciplina.sigla = NEW.sigla;
RETURN NULL;
END;
$avg_grade$ LANGUAGE plpgsql;
CREATE OR REPLACE TRIGGER atualiza_media
AFTER
INSERT ON matricula FOR EACH ROW EXECUTE PROCEDURE avg_grade();