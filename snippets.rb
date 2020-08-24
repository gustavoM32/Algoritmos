require 'json'

snippetsFilePath = '/home/gustavo/.config/Code/User/snippets/cpp.json'
metadataFile = File.open("meta.json")
snippetsFile = File.open(snippetsFilePath)

metadataJson = JSON.parse(metadataFile.read)
snippetsJson = JSON.parse(snippetsFile.read)

allSnippets = metadataJson[:lista.to_s]

def removeComments(code)
	code.gsub /\/\*.*?\*\/\n/m, ''
end

def addSnippets(meta, snippets)
	meta.each_pair do |filename, metadata|
		code = File.open("Códigos/#{filename}").read
		snippets["#{metadata["nome"]} (Lista)"] = {
			"prefix": metadata["atalho"],
			"body": removeComments(code).split("\n"),
			"description": metadata["descrição"]
		}
	end
	snippets
end

finalSnippets = {}
snippetsJson.each_key do |nome|
	finalSnippets[nome] = snippetsJson[nome] unless nome.end_with?(")")
end
finalSnippets = addSnippets(metadataJson, finalSnippets)

metadataFile.close
snippetsFile.close

File.open(snippetsFilePath, "w") { |f| f.write JSON.pretty_generate(finalSnippets) }
puts "Snippets updated!"