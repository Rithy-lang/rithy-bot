import logging
from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler, ContextTypes

# កំណត់ Logging ដើម្បីមើលព័ត៌មាន ឬ Error ផ្សេងៗ
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    level=logging.INFO
)

# ថតរក្សាទុកសំណួរ និងចម្លើយសម្ភាសន៍សម្រាប់ Developer (q1 - q10)
qa_data = {
    "q1": {
        "question": "1. តើអ្វីជា OOP (Object-Oriented Programming) ហើយវាមានគោលការណ៍គ្រឹះអ្វីខ្លះ?",
        "answer": "OOP ជារបៀបសរសេរកូដដែលផ្អែកលើ Object (វត្ថុ)។ គោលការណ៍គ្រឹះទាំង ៤ គឺ៖ Encapsulation, Abstraction, Inheritance, និង Polymorphism។"
    },
    "q2": {
        "question": "2. តើ RESTful API ជាអ្វី?",
        "answer": "RESTful API គឺជា architectural style សម្រាប់ការផ្ទេរទិន្នន័យរវាង Client និង Server ដោយប្រើ HTTP Methods ដូចជា GET, POST, PUT, DELETE ជាដើម។"
    },
    "q3": {
        "question": "3. តើភាពខុសគ្នារវាង Git merge និង Git rebase ជាអ្វី?",
        "answer": "Git merge រួមបញ្ចូលប្រវត្តិ (history) នៃ branch ទាំងពីរចូលគ្នាដោយបង្កើត merge commit ថ្មី ចំណែក Git rebase ផ្លាស់ប្តូរ base commit នៃ branch ទៅលើកំពូលនៃ branch មួយទៀត ដើម្បីឱ្យប្រវត្តិដើរត្រង់ស្អាត។"
    },
    "q4": {
        "question": "4. តើអ្វីជា Database Indexing?",
        "answer": "Indexing គឺជាបច្ចេកទេសដែលប្រើដើម្បីបង្កើនល្បឿនក្នុងការស្វែងរកទិន្នន័យ (Query) នៅក្នុង Database ប៉ុន្តែវាអាចធ្វើឱ្យប្រតិបត្តិការ Insert/Update យឺតជាងមុនបន្តិច។"
    },
    "q5": {
        "question": "5. តើភាពខុសគ្នារវាង SQL និង NoSQL ជាអ្វី?",
        "answer": "SQL (Relational) ប្រើប្រាស់តារាងមានទម្រង់ច្បាស់លាស់ (Structured Schema) ដូចជា MySQL/PostgreSQL។ NoSQL (Non-relational) ផ្ទុកទិន្នន័យបែប Document/Key-Value គ្មានទម្រង់រឹងរូស ដូចជា MongoDB។"
    },
    "q6": {
        "question": "6. តើអ្វីជា SOLID Principles?",
        "answer": "SOLID គឺជាគោលការណ៍ design ៥ យ៉ាង សម្រាប់ Software Development៖\n- S: Single Responsibility\n- O: Open/Closed\n- L: Liskov Substitution\n- I: Interface Segregation\n- D: Dependency Inversion"
    },
    "q7": {
        "question": "7. តើភាពខុសគ្នារវាង Synchronous និង Asynchronous Programming ជាអ្វី?",
        "answer": "Synchronous ប្រតិបត្តិការម្ដងមួយៗតាមលំដាប់ (ចាំកូដមុនចប់ទើបដើរបន្ត)។ Asynchronous អាចដំណើរការ Task ផ្សេងទៀតក្នុងពេលតែមួយដោយមិនចាំបាច់រង់ចាំ Task មុនបញ្ចប់ឡើយ។"
    },
    "q8": {
        "question": "8. តើអ្វីជា Docker ហើយហេតុអ្វីបានជាគេប្រើវា?",
        "answer": "Docker គឺជា platform សម្រាប់បង្កើត រត់ និងគ្រប់គ្រង Application នៅក្នុង Container ដែលធានាថា Application រត់បានរលូនដូចគ្នានៅលើគ្រប់កុំព្យូទ័រ/Server។"
    },
    "q9": {
        "question": "9. តើបច្ចេកទេសសម្អាត និងបង្កើនប្រសិទ្ធភាពកូដ (Code Refactoring) មានប្រយោជន៍អ្វីខ្លះ?",
        "answer": "វាជួយឱ្យកូដងាយស្រួលអាន (Readability) ងាយស្រួលថែទាំ (Maintainability) និងកាត់បន្ថយ Bug ដោយមិនផ្លាស់ប្តូរមុខងារដើមរបស់កម្មវិធីឡើយ។"
    },
    "q10": {
        "question": "10. តើធ្វើដូចម្តេចដើម្បីការពារ Web Application ពី SQL Injection?",
        "answer": "អ្នកអាចការពារបានដោយប្រើ Prepared Statements (Parameterized Queries), ORM ឬការធ្វើ Input Validation/Sanitization ឱ្យបានត្រឹមត្រូវ។"
    }
}

# Generic Handler សម្រាប់រៀបចំចម្លើយ
async def handle_question(update: Update, context: ContextTypes.DEFAULT_TYPE, q_key: str):
    data = qa_data.get(q_key)
    if data:
        message = f"❓ **សំណួរ៖** {data['question']}\n\n💡 **ចម្លើយ៖** {data['answer']}"
        await update.message.reply_text(message, parse_mode='Markdown')

# បង្កើត Command Handlers សម្រាប់ q1 ដល់ q10
async def q1(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q1")
async def q2(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q2")
async def q3(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q3")
async def q4(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q4")
async def q5(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q5")
async def q6(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q6")
async def q7(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q7")
async def q8(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q8")
async def q9(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q9")
async def q10(update: Update, context: ContextTypes.DEFAULT_TYPE): await handle_question(update, context, "q10")

def main():
    # ជំនួស BOT_TOKEN ដោយ TOKEN ដែលទទួលបានពី @BotFather
    TOKEN = "8832353057:AAGvizKZsnYGDV3x3fXz2I5Mt21W-9qQPos"

    app = ApplicationBuilder().token(TOKEN).build()

    # បញ្ចូល Command ទាំង ១០ ទៅក្នុង Bot
    for i in range(1, 11):
        cmd_name = f"q{i}"
        handler_func = globals()[cmd_name]
        app.add_handler(CommandHandler(cmd_name, handler_func))

    print("Bot ដំណើរការហើយ...")
    app.run_polling()

if __name__ == '__main__':
    main()