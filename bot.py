import os
from dotenv import load_dotenv
load_dotenv()
import logging
from threading import Thread
from flask import Flask
from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler, ContextTypes

# ==========================================
# 1. បង្កើត Web Server តូចមួយសម្រាប់ Render/UptimeRobot
# ==========================================
web_app = Flask(__name__)


@web_app.route("/")
def home():
    return "Bot is Alive and Running!"


def run_web():
    # ប្រើ Port របស់ Render ឬ default 8080
    port = int(os.environ.get("PORT", 8080))
    web_app.run(host="0.0.0.0", port=port)


def keep_alive():
    t = Thread(target=run_web)
    t.daemon = True
    t.start()


# ==========================================
# 2. កំណត់ Logging
# ==========================================
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s",
    level=logging.INFO,
)

# ថតរក្សាទុកសំណួរ និងចម្លើយសម្ភាសន៍ការងារទូទៅសម្រាប់ Developer (q1 - q10)
qa_data = {
    "q1": {
        "question": "1. សូមណែនាំខ្លួនអ្នក និងបទពិសោធន៍ធ្វើការងារកន្លងមក?",
"answer": (
    "ខ្ញុំឈ្មោះ រិទ្ធី ជាទីប្រឹក្សា/និស្សិតផ្នែកព័ត៌មានវិទ្យា នៅសាកលវិទ្យាល័យភូមិន្ទភ្នំពេញ។ ",
    "ជំនាញ និង Tech Stack ដែលខ្ញុំប្រកាត់ប្រើប្រាស់រួមមាន Python, JavaScript, និង React។ ",
    "គម្រោងសំខាន់ៗដែលខ្ញុំធ្លាប់បានធ្វើរួមមាន៖ ការអភិវឌ្ឍន៍ Telegram/Discord Bot, ការបង្កើត Web Application ជាមួយ React, និងការសរសេរ Scripts សម្រាប់ប្រព័ន្ធស្វ័យប្រវត្តិកម្ម (Automation)។ ",
    "បំណងប្រាថ្នារបស់ខ្ញុំគឺ ចង់អភិវឌ្ឍសមត្ថភាពបន្ថែមលើផ្នែក Software Engineering និងសម្រេចបាននូវការបង្កើតដំណោះស្រាយបច្ចេកវិទ្យា (Tech Solutions) ដែលមានប្រយោជន៍ដល់សង្គម។"
),
    },
    "q2": {
"question": "2. ហេតុអ្វីបានជាអ្នកចង់ធ្វើការនៅក្រុមហ៊ុនរបស់យើង?",
"answer": (
    "ខ្ញុំមានការចាប់អារម្មណ៍យ៉ាងខ្លាំងលើផលិតផល និងសេវាកម្មបច្ចេកវិទ្យារបស់ក្រុមហ៊ុន ដែលកំពុងមានឥទ្ធិពលវិជ្ជមានក្នុងទីផ្សារ។ ",
    "ក្រៅពីនេះ ខ្ញុំកោតសរសើរចំពោះវប្បធម៌ធ្វើការងារដែលបើកទូលាយ និងគាំទ្រការលូតលាស់របស់បុគ្គលិក។ ",
    "ជាមួយជំនាញ Python, React និងការអភិវឌ្ឍន៍ Software ដែលខ្ញុំមាន ខ្ញុំជឿជាក់ថានឹងអាចចូលរួមចំណែកយ៉ាងសកម្មក្នុងការដោះស្រាយបញ្ហា និងបង្កើតផលប្រយោជន៍ជូនក្រុមហ៊ុន។"
),
    },
    "q3": {
        "question": (
            "3. តើអ្នកដោះស្រាយបញ្ហា Bug យ៉ាងដូចម្តេច (Debugging Process)?"
        ),
        "answer": (
            "ពិនិត្យមើល Error Log -> ប្រើប្រាស់ Debugging Tools"
            " (Breakpoints/Logs) ដើម្បីដាន Data Flow -> ស្វែងរកលើ"
            " Documentation/Community ឬពិភាក្សាជាមួយក្រុម។"
        ),
    },
    "q4": {
        "question": (
            "4. តើអ្នកគ្រប់គ្រងកំណែកូដ (Version Control)"
            " យ៉ាងដូចម្តេចពេលធ្វើការជាក្រុម?"
        ),
        "answer": (
            "ប្រើប្រាស់ Git ដោយអនុវត្តតាម Git Flow (បង្កើត Feature Branch, មិន"
            " Commit លើ main ផ្ទាល់, បង្កើត Pull Request និងធ្វើ Code"
            " Review)។"
        ),
    },
    "q5": {
        "question": "5. តើអ្វីជាភាពខុសគ្នារវាង Frontend និង Backend?",
        "answer": (
            "Frontend គឺជា UI/UX ដែលអ្នកប្រើប្រាស់មើលឃើញ និងមានអន្តរកម្ម (HTML,"
            " CSS, JS, React)។ Backend គឺផ្នែកខាងក្រោយគ្រប់គ្រង Business Logic,"
            " Database, Server និង API។"
        ),
    },
    "q6": {
        "question": (
            "6."
            " តើអ្នកដោះស្រាយយ៉ាងណាពេលមានមតិខុសគ្នាជាមួយមិត្តរួមការងារលើដំណោះស្រាយបច្ចេកទេស?"
        ),
        "answer": (
            "បើកចិត្តស្តាប់ ប្រៀបធៀបចំណុចល្អ/ខ្សោយ (Pros & Cons) ផ្អែកលើ"
            " Performance, Security, Timeline ហើយប្រសិនបើចាំបាច់ ពិគ្រោះជាមួយ"
            " Senior/Tech Lead។"
        ),
    },
    "q7": {
        "question": (
            "7. តើអ្នកធ្វើដូចម្តេចដើម្បីអភិវឌ្ឍជំនាញបច្ចេកវិទ្យារបស់អ្នកឱ្យទាន់សម័យ?"
        ),
        "answer": (
            "អាន Blog បច្ចេកវិទ្យា (Dev.to, Medium)"
            " តាមដានព័ត៌មានផ្លូវការរបស់ Framework/Library ធ្វើ Side Projects"
            " និងចូលរួមក្នុង Developer Community។"
        ),
    },
    "q8": {
        "question": "8. តើអ្វីជា OOP (Object-Oriented Programming)?",
        "answer": (
            "OOP ជារបៀបសរសេរកូដផ្អែកលើ Object ដោយមានគោលការណ៍គ្រឹះ ៤ គឺ"
            " Encapsulation, Abstraction, Inheritance, និង Polymorphism។"
        ),
    },
    "q9": {
        "question": "9. តើអ្វីជា RESTful API?",
        "answer": (
            "RESTful API គឺជា architectural style សម្រាប់ការផ្ទេរទិន្នន័យរវាង Client"
            " និង Server ដោយប្រើ HTTP Methods (GET, POST, PUT, DELETE)។"
        ),
    },
    "q10": {
        "question": "10. តើអ្វីជា SOLID Principles?",
        "answer": (
            "SOLID គឺជាគោលការណ៍ Clean Code ៥ យ៉ាង៖ Single Responsibility,"
            " Open/Closed, Liskov Substitution, Interface Segregation, និង"
            " Dependency Inversion។"
        ),
    },
}


# មុខងារ /start ដើម្បីចាប់ផ្ដើមដំណើរការ
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    welcome_message = (
        "👋 **សួស្តី! ស្វាគមន៍មកកាន់ Developer Interview Prep Bot**\n\n"
        "សូមជ្រើសរើស ឬវាយពាក្យបញ្ជាខាងក្រោមដើម្បីមើលសំណួរ និងចម្លើយសម្ភាសន៍៖\n\n"
        "/q1 - ១. ការណែនាំខ្លួន\n"
        "/q2 - ២. ហេតុអ្វីជ្រើសរើសក្រុមហ៊ុននេះ\n"
        "/q3 - ៣. របៀបដោះស្រាយ Bug (Debugging)\n"
        "/q4 - ៤. ការប្រើប្រាស់ Git/Version Control\n"
        "/q5 - ៥. Frontend vs Backend\n"
        "/q6 - ៦. ការដោះស្រាយទំនាស់មតិបច្ចេកទេស\n"
        "/q7 - ៧. ការធ្វើបច្ចុប្បន្នភាពជំនាញ (Keep Up-to-date)\n"
        "/q8 - ៨. គោលការណ៍ OOP\n"
        "/q9 - ៩. យល់ដឹងពី RESTful API\n"
        "/q10 - ១០. គោលការណ៍ SOLID Principles"
    )
    await update.message.reply_text(welcome_message, parse_mode="Markdown")


# Generic Handler សម្រាប់ឆ្លើយតបសំណួរ q1 - q10
async def handle_question(
    update: Update, context: ContextTypes.DEFAULT_TYPE, q_key: str
):
    data = qa_data.get(q_key)
    if data:
        message = (
            f"❓ **សំណួរ៖** {data['question']}\n\n💡 **ចម្លើយណែនាំ៖**"
            f" {data['answer']}"
        )
        await update.message.reply_text(message, parse_mode="Markdown")


# Command Handlers សម្រាប់ q1 ដល់ q10
async def q1(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q1")


async def q2(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q2")


async def q3(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q3")


async def q4(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q4")


async def q5(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q5")


async def q6(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q6")


async def q7(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q7")


async def q8(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q8")


async def q9(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q9")


async def q10(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await handle_question(update, context, "q10")


def main():
    TOKEN = os.getenv("TOKEN")
    
    if not TOKEN:
        print("Error: TOKEN environment variable is missing!")
        return

    app = ApplicationBuilder().token(TOKEN).build()

    # បន្ថែម /start command
    app.add_handler(CommandHandler("start", start))

    # បញ្ចូល Command q1 ដល់ q10
    for i in range(1, 11):
        cmd_name = f"q{i}"
        handler_func = globals()[cmd_name]
        app.add_handler(CommandHandler(cmd_name, handler_func))

    print("Bot ដំណើរការហើយ...")
    app.run_polling()

if __name__ == "__main__":
    main()
