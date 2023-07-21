from fastapi import FastAPI
from app.routes import db_routes

app = FastAPI()

app.include_router(db_routes.router, prefix="/db", tags=["Database"])

