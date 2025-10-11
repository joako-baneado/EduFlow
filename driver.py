from antlr4 import *
from EduFlowLexer import EduFlowLexer
from EduFlowParser import EduFlowParser

input_stream = FileStream("Test.in", encoding='utf-8')
lexer = EduFlowLexer(input_stream)
stream = CommonTokenStream(lexer)
parser = EduFlowParser(stream)
tree = parser.program()
print(tree.toStringTree(recog=parser))