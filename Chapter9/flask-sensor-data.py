from influxdb_client import InfluxDBClient, Point
from flask import Flask

app = Flask(__name__)

bucket = "ch12"
client = InfluxDBClient(url="http://localhost:8086", token="3563QrhOmUNToC_zA_ALsfqaN9LlBFk9B2r3nqSTtZoa32PdfB1xz7_SbQu5vLsH7AxJAfj4QXVYsmIKMnP2EQ==", org="packt")

query_api = client.query_api()

@app.route('/')
def get_last_reading():
    result = query_api.query('from(bucket:"ch12") |> range(start: -10m) |> last()')
    results = []

    for table in result:
          for record in table.records:
                  results.append((record.get_field(), record.get_value()))

    final_result = results[0]
    return final_result[1]
