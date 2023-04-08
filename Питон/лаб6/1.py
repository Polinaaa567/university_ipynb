# 1
class BigBell:
    zvuc = 0
    def sound(self):
        if not self.zvuc:
            print('ding')
            self.zvuc = 1
        else:
            print('dong')
            self.zvuc = 0



bell =BigBell()
bell.sound()
bell.sound()
bell.sound()
bell.sound()
