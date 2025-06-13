# 📊 Sistema de Análise de Transações Bancárias

Este projeto tem como objetivo a implementação de um sistema em C para a **análise de transações financeiras** armazenadas em um arquivo binário, utilizando estrutura modular, ponteiros, técnicas de busca, ordenação, geração de relatórios e interação via terminal.

---

## 📁 Estrutura do Projeto

```
TrabalhoFinal_Alex/
├── src/                #Arquivos-fontes     
│   ├── B1/
│   ├── B2/
│   └── ...
├── include/            #Arquivos .h
│   ├── funcionalides.h
│   └── modelRecord.h
├── bin/            #Binários
│   ├── bankdataset.data
│   └── ...
├── data/            #Arquivos de entrada e saída
│   ├── relatorio_registros.txt
│   └── ...
├── CMakeLists.txt          # Script de build com CMake
└── README.md            # Documentação
```

---

## 💡 Descrição do Sistema

O sistema manipula um arquivo binário `bankdataset.dat` contendo registros financeiros agregados por:

- **Data**
- **Domínio econômico (ex: RESTAURANT, RETAIL, PUBLIC)**
- **Localidade**
- **Valor total da transação**
- **Quantidade de transações**

```c
typedef struct {
    char date[50];            
    char domain[50];          
    char location[50];        
    int value;                
    int transaction_count;    
} Record;
```

---

## 🧭 Funcionalidades do Sistema

Ao iniciar o programa, será exibido um menu com as seguintes opções:

### Básicas
- `[B1]` Listar todos os registros (terminal + `relatorio_registros.txt`)
- `[B2]` Filtrar registros por domínio (exibe + `filtro_dominio_<dominio>.txt`)

### Intermediárias
- `[M1]` Somar total de transações por domínio (`resumo_transacoes.txt`)
- `[M2]` Exportar registros por data (`export_YYYYMMDD.csv`)
- `[M3]` Calcular média de valor por transação por localidade (`media_por_localidade.txt`)

### Avançadas
- `[A1]` Buscar registro por valor (sequencial ou binária → `busca_valor_X.txt`)
- `[A2]` Listar localidades distintas ordenadas (`localidades_ordenadas.txt`)

### Extras
- `[E1]` Inserir novo registro no arquivo
- `[E2]` Gerar relatório consolidado de indicadores (`relatorio.txt`)

---

## 🗃️ Arquivos Gerados

Durante a execução, o sistema cria relatórios em `.txt` ou `.csv`, como:

- `relatorio_registros.txt`
- `filtro_dominio_<DOMÍNIO>.txt`
- `export_YYYYMMDD.csv`
- `resumo_transacoes.txt`
- `media_por_localidade.txt`
- `busca_valor_X.txt`
- `localidades_ordenadas.txt`
- `relatorio.txt`

---

> Projeto acadêmico — FATEC Ourinhos — 2025