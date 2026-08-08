# bot.py
from telegram import Update
from telegram.ext import ApplicationBuilder, CommandHandler, ContextTypes

BOT_TOKEN = ""

q1_text = """Developer
A developer is responsible for writing code, creating, and developing applications or websites. They use programming languages such as C++, Java, Python, and JavaScript to create various functions. Developers are also responsible for fixing bugs and making the application work well."""


q2_text = """Software Architect

A software architect plans and designs the overall structure of the application. They determine the technology, development methods, and ensure that the system is stable, secure, and easy to expand in the future."""

q3_text = """Tester (QA Engineer)

A tester or QA engineer is responsible for testing the application to find errors and ensure product quality. They test various functions, find problems, and report them to the developer team for correction."""

q4_text = """UX Designer

UX Designers focus on making applications or websites easy to use and attractive. They study user needs, create prototypes, and improve the user experience."""

q5_text = """Business Analyst

A Business Analyst is responsible for gathering and analyzing the needs of a client or organization. They liaise between technical teams and clients to ensure that the software they create meets their needs."""

q6_text = """Network Engineer

A Network Engineer is responsible for designing, installing, and managing computer networks. They ensure that the Internet and networks in an organization are functioning well, securely, and efficiently."""

q7_text = """System Administrator

A System Administrator is responsible for managing an organization’s servers, operating systems, and IT resources. They install software, maintain systems, and ensure that the systems are running smoothly."""

q8_text = """Database Administrator (DBA)

A Database Administrator is responsible for managing databases. They organize, store, back up, and protect data from loss or unauthorized access."""

q9_text = """Cybersecurity Specialist

A Cybersecurity Specialist is responsible for protecting systems and data from cyberattacks. They monitor risks, find vulnerabilities, and implement security measures to protect critical information."""

q10_text = """Project Manager

A Project Manager leads and manages an entire IT project. They plan, allocate work, manage time and budget, and ensure that the project is completed on time and on budget."""

async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    text = (
        "Welcome!\n\n"
        "Available commands:\n"
        "/q1 - Developer\n"
        "/q2 - Software Architect\n"
        "/q3 - Tester (QA Engineer)\n"
        "/q4 - UX Designer\n"
        "/q5 - Business Analyst\n"
        "/q6 - Network Engineer\n"
        "/q7 - System Administrator\n"
        "/q8 - Database Administrator (DBA)\n"
        "/q9 - Cybersecurity Specialist\n"
        "/q10 - Project Manager"
    )
    await update.message.reply_text(text)

async def q1(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q1_text)

async def q2(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q2_text)

async def q3(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q3_text)

async def q4(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q4_text)

async def q5(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q5_text)

async def q6(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q6_text)

async def q7(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q7_text)

async def q8(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q8_text)

async def q9(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q9_text)

async def q10(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await update.message.reply_text(q10_text)

def main():
    app = ApplicationBuilder().token(BOT_TOKEN).build()

    app.add_handler(CommandHandler("start", start))
    app.add_handler(CommandHandler("q1", q1))
    app.add_handler(CommandHandler("q2", q2))
    app.add_handler(CommandHandler("q3", q3))
    app.add_handler(CommandHandler("q4", q4))
    app.add_handler(CommandHandler("q5", q5))
    app.add_handler(CommandHandler("q6", q6))
    app.add_handler(CommandHandler("q7", q7))
    app.add_handler(CommandHandler("q8", q8))
    app.add_handler(CommandHandler("q9", q9))
    app.add_handler(CommandHandler("q10", q10))

    print("Bot is running...")
    app.run_polling()

if __name__ == "__main__":
    main()
    