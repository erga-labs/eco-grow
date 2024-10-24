
from ML.dataset.secret import AppwriteSecrets
from appwrite.client import Client
from appwrite.services.databases import Databases


client = (
    Client()
        .set_endpoint(AppwriteSecrets.ENDPOINT)
        .set_project(AppwriteSecrets.PROJECT_ID)
        .set_key(AppwriteSecrets.API_KEY)
)

database = Databases(client)


def get_record():
    # fetching the sensors records
    result = database.list_documents(
        database_id=AppwriteSecrets.DB_ID,
        collection_id=AppwriteSecrets.COLLECTION_ID,
    )
    return result['documents'][-1]


if __name__ == '__main__':
    print(get_record())
