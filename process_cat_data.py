import pandas
import datetime
pandas.options.plotting.backend = "plotly"
df=pandas.read_csv('./detection.log2')
res=df.apply(lambda x: x[0].split(": ")[1], axis=1, raw=True).apply(lambda x: datetime.datetime.strptime(x, '%a %b %d %H:%M:%S %Y'))
#fig=res.groupby(lambda x: res[x]).count().plot()
res=res.apply(lambda x: x + datetime.timedelta(hours=2))
fig=res.groupby(lambda x: res[x]).count().plot(kind="scatter").write_html("output.html")
#res2.groupby(lambda x: res[x]).count().plot(kind="scatter").write_html("output.html")
#res.groupby(lambda x: res[x]).count().plot(kind="scatter").write_html("result.html")
print("done!")
