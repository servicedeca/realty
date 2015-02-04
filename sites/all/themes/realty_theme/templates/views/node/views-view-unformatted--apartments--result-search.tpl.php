<div class="container fin">
  <div class="col-xs-12 breadcrumb-block">
    <ol class="breadcrumb zero-padding breadcrumbfix">
      <li><a href="#">Главная</a></li>
      <li class="active"><a href="#">Результаты поиска</a></li>
      <li><a href="#">Жилой комплекс</a></li>
    </ol>
  </div>
  <div class="col-xs-12 table-block text-center zero-padding">
    <table class="table issue-table display" id="example">
      <thead>
      <tr>
        <th id="bn"><?php print t('Apartment') ?></th>
        <th><?php print t('Area') ?></th>
        <th><?php print t('Developer') ?></th>
        <th><?php print t('RC') ?></th>
        <th><?php print t('Address') ?></th>
        <th><?php print t('Deadline') ?></th>
        <th><?php print t('Doors') ?>.&nbsp&nbsp</th>
        <th><?php print t('floor') ?>&nbsp&nbsp</th>
        <th ><?php print t('S') ?></th>
        <th><?php print t('Price') ?>&nbsp&nbsp<br>м<sup>2</sup>&nbsp&nbsp</th>
        <th class="none-border-right"><?php print t('Coast') ?></th>
        <th></th>
      </tr>
      <tbody>
        <?php if (!empty($view->result)):?>
          <?php foreach($apartments as $key=>$apartment) :?>
            <?php if ($apartment['status'] == 0):?>
              <tr  rel="tooltip" data-placement="top" title="Квартира забронирована" class="booking">
            <?php else: ?>
              <tr>
            <?php endif?>
            <td scope="row">
              <div class="flat-number">
                <?php print $apartment['number']?>
              </div>
            </td>
            <td>
              <?php print $apartment['area']?>
            </td>
            <td>
              <?php print $apartment['developer']?>
            </td>
            <td>
              <?php print $apartment['complex']?>
            </td>
            <td>
              <?php print $apartment['address']?>
            </td>
            <td>
              <?php print $apartment['quarter'] . 'кв.' . $apartment['year'] ?>
            </td>
            <td>
              <?php print $apartment['rooms']?>
            </td>
            <td>
              <?php print $apartment['floor'] . '/' . $apartment['home_floor'] ?>
            </td>
            <td>
              <?php print $apartment['sq'] . 'м'?><sup>2</sup>
            </td>
            <td>
              <?php print $apartment['price'] . 'т.р.'?>
            </td>
            <td>
              <?php print $apartment['coast'] . 'т.р.'?>
            </td>
            <td>
              <?php print $apartment['apartment_comparison'];?>
            </td>
          </tr>
        <?php endforeach;?>
        <?php endif; ?>

      </tbody>
      </thead>
    </table>
  </div>
</div>