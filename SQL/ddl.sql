CREATE TABLE aluno (
    nmatr INTEGER PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    idade INTEGER NOT NULL,
    datanasc DATE NOT NULL,
    cidadeorigem VARCHAR(50) NOT NULL
);
CREATE TABLE professor (
    nfunc INTEGER PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    idade INTEGER NOT NULL,
    titulacao VARCHAR(50) NOT NULL
);
CREATE TABLE disciplina (
    sigla VARCHAR(10) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    ncred INTEGER NOT NULL,
    professor INTEGER NOT NULL,
    livro VARCHAR(50) NOT NULL,
    FOREIGN KEY (professor) REFERENCES professor(nfunc)
);
CREATE TABLE turma (
    sigla VARCHAR(10) NOT NULL,
    letra VARCHAR(1) NOT NULL,
    nalunos INTEGER NOT NULL,
    PRIMARY KEY (sigla, letra),
    FOREIGN KEY (sigla) REFERENCES disciplina(sigla)
);
CREATE TABLE matricula (
    sigla VARCHAR(10) NOT NULL,
    letra VARCHAR(1) NOT NULL,
    nmatr INTEGER NOT NULL,
    ano INTEGER NOT NULL,
    nota INTEGER NOT NULL,
    PRIMARY KEY (sigla, letra, nmatr),
    FOREIGN KEY (sigla, letra) REFERENCES turma(sigla, letra),
    FOREIGN KEY (nmatr) REFERENCES aluno(nmatr)
);