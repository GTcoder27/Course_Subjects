from langchain_community.document_loaders import TextLoader,PyPDFLoader,DirectoryLoader,WebBaseLoader
from bs4 import BeautifulSoup

loader1 = TextLoader("articles.txt")
loader2 = PyPDFLoader("system_design.pdf")

document1 = loader1.load()
# print(document1[0].page_content)
document2 = loader2.load()
# print(document2[0].page_content)

loader3 = DirectoryLoader(              
    path='',       # if inside any folder so we can give the path of that folder
    glob='*.pdf',
    loader_cls=PyPDFLoader
)
# "**./*.txt" -> All txt files in all subfolders
# "*.pdf"     -> All pdf files in the root directory
# "data/*.csv" -> All .csv files in data/ folder
# "**/*"       -> All files (any type ,all folders)

document3 = loader3.load()
document4 = loader3.lazy_load()
# for i in document4:
#     print(i.metadata)


loader5 = WebBaseLoader("https://www.amazon.in/Apple-2026-MacBook-Laptop-chip/dp/B0GR6HXPB9/ref=asc_df_B0GR6HXPB9?mcid=56af20dcad7a3803b8d2e1b6aaf0148c&tag=googleshopdes-21&linkCode=df0&hvadid=794212938611&hvpos=&hvnetw=g&hvrand=11438456298625775304&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9181853&hvtargid=pla-2470150962683&hvocijid=11438456298625775304-B0GR6HXPB9-&hvexpln=0&gad_source=1&th=1")
document5 = loader5.load()
print(document5)








