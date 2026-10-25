from langchain_text_splitters import CharacterTextSplitter,RecursiveCharacterTextSplitter
from langchain_community.document_loaders import TextLoader

loader = TextLoader('articles.txt')

doc = loader.load()

# splitter1 = CharacterTextSplitter(
#     chunk_size=50,
#     chunk_overlap=10,
#     separator=''
# )
splitter2 = RecursiveCharacterTextSplitter(
    chunk_size=50,
    chunk_overlap=10,
    separators=["\n\n","\n"," ","."]
)
res = splitter2.split_text(str(doc[0].page_content))
res = splitter2.split_documents(doc)
print(res[0])
 


