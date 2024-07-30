from datetime import datetime

class Evento:
    def __init__(self, nome, inicio, fim):
        self.nome = nome
        self.inicio = inicio
        self.fim = fim
        
class Agenda:
    def __init__(self):
        self.eventos: list[Evento] = []
        
    def adicionar_evento(self, evento: Evento):
        if evento.fim <= evento.inicio:
            raise ValueError("A data de término deve ser posterior à data de início.")
        
        for ev in self.eventos:
            if ev.nome == evento.nome:
                raise ValueError("Um evento com mesmo nome já existe na agenda.")
            
            if evento.inicio < ev.fim and evento.fim > ev.inicio:
                return False
            
        self.eventos.append(evento)
        return True
        
    def remover_evento(self, nome):
        for evento in self.eventos:
            if evento.nome == nome:
                self.eventos.remove(evento)
                return True
        return False
        
    def mostrar_agenda(self):
        if not self.eventos:
            return "Nenhum evento agendado."
        return "\n".join([f"{evento.nome}: {evento.inicio} a {evento.fim}\n" for evento in self.eventos])

    def sair(self):
        return "Saindo da aplicação."


def main():
    agenda = Agenda()
    while True:
        acao = input("Digite a ação (adicionar, remover, mostrar, sair): ").strip().lower()
        
        if acao == "adicionar":
            nome = input("Digite o nome do evento: ")
            try:
                inicio = datetime.strptime(input("Digite a hora de início (YYYY-MM-DD HH:MM): "), "%Y-%m-%d %H:%M")
                fim = datetime.strptime(input("Digite a hora de término (YYYY-MM-DD HH:MM): "), "%Y-%m-%d %H:%M")
                
                evento = Evento(nome, inicio, fim)
                if agenda.adicionar_evento(evento):
                    print("Evento adicionado com sucesso.")
                else:
                    print("Conflito de agendamento detectado.")
            except ValueError as e:
                print(f"Erro: {e}")
        
        elif acao == "remover":
            nome = input("Digite o nome do evento para remover: ")
            if agenda.remover_evento(nome):
                print("Evento removido com sucesso.")
            else:
                print("Evento não encontrado.")
                
        elif acao == "mostrar":
            print(agenda.mostrar_agenda())
        
        elif acao == "sair":
            print(agenda.sair())
            break
        
        else:
            print("Ação inválida. Tente novamente.")

if __name__ == "__main__":
    main()
