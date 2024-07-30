INSERT INTO aluno (nmatr, nome, idade, datanasc, cidadeorigem) VALUES
(1, 'João', 20, '2001-01-01', 'São Paulo'),
(2, 'Maria', 21, '2000-02-02', 'Rio de Janeiro');

INSERT INTO professor (nfunc, nome, idade, titulacao) VALUES
(1, 'Prof. Silva', 40, 'Doutor'),
(2, 'Prof. Souza', 45, 'Mestre');

INSERT INTO disciplina (sigla, nome, ncred, professor, livro) VALUES
('D1', 'Disciplina 1', 10, 1, 'Livro 1'),
('D2', 'Disciplina 2', 5, 2, 'Livro 2'),
('D3', 'Disciplina 3', 15, 1, 'Livro 3');

INSERT INTO turma (sigla, letra, nalunos) VALUES
('D1', 'A', 30),
('D2', 'B', 25);
('D3', 'A', 20);

INSERT INTO matricula (sigla, letra, nmatr, ano, nota) VALUES
('D1', 'A', 1, 2022, 8),
('D2', 'B', 2, 2022, 9);