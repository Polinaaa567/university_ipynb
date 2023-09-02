class MailClient:
    def __init__(self, server, user):
        self.server = server
        self.user = user

    def receive_mail(self):
        if self.server:
            self.server = []
        return "Все сообщения получены"

    def send_mail(self, server1, user1, message):
        server1[user1] = message
        return server1


server = []
user1 = 'ivanov'
client1 = MailClient(server, user1)
print(client1.receive_mail())
server1 = {}
server.append(server1)
user2 = 'antonov'
client2 = MailClient(server, user2)
message1 = 'Привет, как дела?'
print(client1.send_mail(server1, user2, message1))
print(client2.receive_mail())
message2 = 'Привет,  у меня все классно, а ты как поживаешь?'
server.append(server1)
print(client2.send_mail(server1, user1, message2))
print(client1.receive_mail())
