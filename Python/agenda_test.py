import pytest
from main import Agenda, Evento
from datetime import datetime, timedelta


def test_adicionar_evento():
    agenda = Agenda()
    
    data_inicio = datetime.strptime("2024-01-01 10:00", "%Y-%m-%d %H:%M")
    data_termino = datetime.strptime("2024-01-01 12:00", "%Y-%m-%d %H:%M")
    
    evento = Evento("Evento 1", data_inicio, data_termino)

    agenda.adicionar_evento(evento)
    assert evento in agenda.eventos
    

def test_adicionar_evento_falha_se_termino_nao_posterior_ao_inicio():
    agenda = Agenda()
    
    data_inicio = datetime.now()
    data_termino = datetime.now() - timedelta(hours=1)
    
    evento = Evento("Evento 1", data_inicio, data_termino)

    with pytest.raises(ValueError) as excinfo:
        agenda.adicionar_evento(evento)
        
    assert str(excinfo.value) == "A data de término deve ser posterior à data de início."

def test_adicionar_evento_nome_repetido():
    agenda = Agenda()
    
    data_inicio = datetime.now()
    data_termino = data_inicio + timedelta(hours=2)
    agenda.adicionar_evento(Evento("Evento 3", data_inicio, data_termino))
    
    data_inicio2 = datetime.now() + timedelta(days=1)
    data_termino2 = data_inicio2 + timedelta(hours=2)
    
    try:
        agenda.adicionar_evento(Evento("Evento 3", data_inicio2, data_termino2))
    except ValueError as e:
        assert str(e) == "Um evento com mesmo nome já existe na agenda."
    
    eventos_nomes = [evento.nome for evento in agenda.eventos]
    assert eventos_nomes.count("Evento 3") == 1

def test_conflito_inicio_dentro_termino_depois():
    agenda = Agenda()
    
    data_inicio = datetime.strptime("2024-01-01 10:00", "%Y-%m-%d %H:%M")
    data_termino = datetime.strptime("2024-01-01 12:00", "%Y-%m-%d %H:%M")
    
    evento1 = Evento("Evento 1", data_inicio, data_termino)
    agenda.adicionar_evento(evento1)
    
    data_inicio = datetime.strptime("2024-01-01 11:00", "%Y-%m-%d %H:%M")
    data_termino = datetime.strptime("2024-01-01 13:00", "%Y-%m-%d %H:%M")
    
    evento2 = Evento("Evento 2", data_inicio, data_termino)
    res = agenda.adicionar_evento(evento2)
    assert res == False
    
def test_conflito_inicio_antes_termino_dentro():
    agenda = Agenda()
    
    data_inicio = datetime.strptime("2024-01-01 10:00", "%Y-%m-%d %H:%M")
    data_termino = datetime.strptime("2024-01-01 12:00", "%Y-%m-%d %H:%M")
    
    evento1 = Evento("Evento 1", data_inicio, data_termino)
    agenda.adicionar_evento(evento1)
    
    data_inicio = datetime.strptime("2024-01-01 09:30", "%Y-%m-%d %H:%M")
    data_termino = datetime.strptime("2024-01-01 11:00", "%Y-%m-%d %H:%M")
    
    evento2 = Evento("Evento 2", data_inicio, data_termino)
    res = agenda.adicionar_evento(evento2)
        
    assert res == False

def test_conflito_cobre_evento_existente():
    agenda = Agenda()
    
    data_inicio1 = datetime.strptime("2024-01-01 10:00", "%Y-%m-%d %H:%M")
    data_termino1 = datetime.strptime("2024-01-01 12:00", "%Y-%m-%d %H:%M")
    
    evento1 = Evento("Evento 1", data_inicio1, data_termino1)
    agenda.adicionar_evento(evento1)
    
    data_inicio1 = datetime.strptime("2024-01-01 09:00", "%Y-%m-%d %H:%M")
    data_termino1 = datetime.strptime("2024-01-01 13:00", "%Y-%m-%d %H:%M")
    
    evento2 = Evento("Evento 2", data_inicio1, data_termino1)
    res = agenda.adicionar_evento(evento2)
        
    assert res == False
    
def test_remover_evento():
    agenda = Agenda()
     
    data_inicio = datetime.now()
    data_termino = datetime.now() + timedelta(5)
    evento = Evento("Evento 1", data_inicio, data_termino)
    agenda.adicionar_evento(evento)
    
    resultado = agenda.remover_evento("Evento 1")    
    assert resultado == True

def test_remover_evento_nao_existente():
    agenda = Agenda()
    
    resultado = agenda.remover_evento("Evento Inexistente")
    
    assert resultado == False
    
def test_mostrar_agenda():
    agenda = Agenda()
    
    data_inicio = datetime.now()
    data_termino = datetime.now() + timedelta(days=5)
    
    evento = Evento("Evento 1", data_inicio, data_termino)
    agenda.adicionar_evento(evento)
    
    output = agenda.mostrar_agenda()
    expected_output = f"Evento 1: {data_inicio} a {data_termino}\n"
    
    assert output == expected_output, f"Esperado: {expected_output}, mas obteve: {output}"

def test_mostrar_agenda_sem_eventos():
    agenda = Agenda()
    
    resultado = agenda.mostrar_agenda()
    
    assert resultado == "Nenhum evento agendado."

def test_sair():
    agenda = Agenda()
    
    output = agenda.sair()
    expected_output = "Saindo da aplicação."
    
    assert output == expected_output, f"Esperado: {expected_output}, mas obteve: {output}"
