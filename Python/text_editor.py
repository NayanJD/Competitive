

class TextEditor:
    def __init__(self):
        self.text = ''
        self.clipboard = ''

    def processCommands(self, commands: list[str]):
        for command in commands:
            comps = command.split(" ")

            if comps[0] == "INSERT":
                self.processInsert(comps[1])
            elif comps[0] == "COPY":
                # print(int(comps[1]), int(comps[2]))
                self.processCopy(int(comps[1]), int(comps[2]))
            elif comps[0] == "PASTE":
                self.processPaste()
            elif comps[0] == "DELETE":
                # print(int(comps[1]), int(comps[2]))
                self.processDelete(int(comps[1]), int(comps[2]))
            elif comps[0] == "PRINT":
                self.processPrint()

    def processInsert(self, text: str):
        self.text += text
    
    def processDelete(self, i: int , j: int):
        self.text = self.text[0: i] + self.text[j + 1: len(self.text)]

    def processPrint(self):
        print(self.text)

    def processCopy(self, i: int, j: int):
        self.clipboard = self.text[i: j + 1]

    def processPaste(self):
        self.text = self.text + self.clipboard

if __name__ == '__main__':
    commands = [
        "INSERT Nayan", 
        "INSERT Das", 
        "COPY 0 4", 
        "PASTE", 
        "PRINT", 
        "DELETE 0 4", 
        "PRINT", 
        # "UNDO", 
        # "UNDO", 
        "PRINT", 
        # "REDO", 
        "PRINT", 
        # "REDO"
    ]

    editor = TextEditor()

    editor.processCommands(commands)

