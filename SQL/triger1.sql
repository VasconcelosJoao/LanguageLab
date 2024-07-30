CREATE OR REPLACE FUNCTION title_update() RETURNS trigger AS $title_update$ 
BEGIN
    if OLD.title = NEW.title THEN RETURN NEW;
    ELSIF OLD.title = 'Titular' and NEW.title = 'Catedrático' THEN RETURN NEW;
    ELSIF OLD.title = 'Livre-docente' and NEW.title = 'Titular' THEN RETURN NEW; 
    ELSIF OLD.title = 'Doutor' and NEW.title = 'Livre-docente' THEN RETURN NEW; 
    ELSIF OLD.title = 'Mestre' and NEW.title = 'Doutor' THEN RETURN NEW;
    ELSIF OLD.title = 'Bacharel' and NEW.title = 'Mestre' THEN RETURN NEW;
    ELSE RAISE EXCEPTION 'Toma no seu cu';
    END IF;
END;
$title_update$;